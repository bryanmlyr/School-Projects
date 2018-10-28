import System.Environment

liftM' :: (Monad m) => (a1 -> r) -> m a1 -> m r
liftM' f m1 = do { x1 <- m1; return (f x1) }

debruijn_combinations :: Int -> String -> [String]
debruijn_combinations n s = [x | x <- mapM (const s) [1..n]]

string_splitter :: Int -> String -> String
string_splitter 0 _ = ""
string_splitter n (h:t) | n > length(h:t) = (h:t)
string_splitter n (h:t) = h : string_splitter (n-1) t

debruijn_splitter' :: Int -> Int -> String -> [String]
debruijn_splitter' n 0 (h:t) = []
debruijn_splitter' n x (h:t)    | length (string_splitter n (h:t)) == n =
                                        [] ++ string_splitter n (h:t)
                                        : debruijn_splitter' n (x-1) t
                                | otherwise = []

debruijn_single_checker :: String -> [String] -> Bool
debruijn_single_checker s [] = False
debruijn_single_checker s (h:t) | s == h = True
                                | otherwise = debruijn_single_checker s t

debruijn_checker :: [String] -> [String] -> [Bool]
debruijn_checker [] s = []
debruijn_checker (h:t) s = debruijn_single_checker h s : debruijn_checker t s

debruijn_checker' :: [Bool] -> Bool
debruijn_checker' [] = True
debruijn_checker' (h:t) | h == False = False
                        | otherwise = debruijn_checker' t

--         SIZE   INPUT     ALPHABET  RET
checker :: Int -> String -> String -> IO ()
checker a b c | a < 1 || b == "" || c == "" = putStrLn "KO"
checker a b c   | debruijn_checker' (debruijn_checker
                        (debruijn_combinations a c)
                        (debruijn_splitter' a
                        (length (debruijn_combinations a c)) (b ++ b))) == True
                        = putStrLn "OK"
                | otherwise = putStrLn "KO"

calibr :: String -> Int -> [String] -> [String]
calibr a x (h:t)        | h /= a = calibr a x t
                        | otherwise = take (x) (h:t)

same :: [String] -> [String] -> Bool
same [] [] = True
same (h:t) (x:y)        | h /= x = False
                        | otherwise = same t y

--        SIZE   INPUT1    INPUT2    ALPHABET  RET
unique :: Int -> String -> String -> String -> IO ()
unique a b c d | a < 1 || b == "" || c == "" || d == "" || (length b) /= (length c) = putStrLn "KO"
unique a b c d  | same  (debruijn_splitter' a (length (debruijn_combinations a d)) (b ++ b))
                        (calibr ((debruijn_splitter' a (length (debruijn_combinations a d)) (b ++ b)) !! 0)
                                (length (debruijn_combinations a d))
                                (debruijn_splitter' a (length (debruijn_combinations a d) * 2) (c ++ c))
                        ) == False
                        && debruijn_checker'
                        (debruijn_checker
                                (debruijn_combinations a d)
                                (debruijn_splitter' a (length (debruijn_combinations a d)) (b ++ b))
                        ) == True
                        && debruijn_checker'
                        (debruijn_checker
                                (debruijn_combinations a d)
                                (debruijn_splitter' a (length (debruijn_combinations a d)) (c ++ c))
                        ) == True
                        = putStrLn "OK"
                | otherwise = putStrLn "KO"

get_alphabet :: [String] -> String
get_alphabet a  | (a !! 1) /= "--check" && (a !! 1) /= "--clean" && (a !! 1) /= "--unique" = a !! 1
                | otherwise = "01"

clean :: Int -> [String] -> String -> IO ()
clean a [] c = putStr ""
clean a (h:t) c = do
                        if      (debruijn_checker'
                                        (debruijn_checker
                                                (debruijn_combinations a c)
                                                (debruijn_splitter' a (length (debruijn_combinations a c)) (h ++ h)))
                                == True)
                        then putStrLn h
                        else putStr ""
                        clean a (t) c

options :: [String] -> [String] -> IO ()
options a x     | (a !! 1 == "--check" || a !! 2 == "--check") =
                        checker (read (a !! 0) :: Int) (x !! 0) (get_alphabet a)
                | (a !! 1 == "--unique" || a !! 2 == "--unique") =
                        unique (read (a !! 0) :: Int) (x !! 0) (x !! 1) (get_alphabet a)
                | (a !! 1 == "--clean" || a !! 2 == "--clean") =
                        clean (read (a !! 0) :: Int) x (get_alphabet a)
                | otherwise = putStrLn "ERROR"

getList :: IO [String]
getList = do
                line <- getLine
                if line == "END" then return []
                else fmap (line:) getList

launcher :: [String] -> IO ()
launcher a     | (a !! 1 == "--check" || a !! 2 == "--check") =
                        do
                                x <- getLine; options a [([] ++ x)]
                | (a !! 1 == "--unique" || a !! 2 == "--unique") =
                        do
                                x <- getLine
                                y <- getLine; options a ([([] ++ x)] ++ [([] ++ y)])
                | (a !! 1 == "--clean" || a !! 2 == "--clean") =
                        do
                                x <- getList; options a x
                | otherwise = putStrLn "Non-supported parameter"

transform_opt :: [String] -> [String]
transform_opt a | length a == 2 && ((a !! 1) == "--check" || (a !! 1) == "--clean" || (a !! 1) == "--unique") = [a !! 0] ++ ["01"] ++ [a !! 1]
                | otherwise = a

main = do
        x <- getArgs
        if length x == 0 then
                do
                        putStrLn "USAGE: ./deBruijn n [a] [--check|--unique|--clean]"
                        putStrLn "\t--check check if a sequence is a de Bruijn sequence"
                        putStrLn "\t--unique check if 2 sequences are distinct de Bruijn sequences"
                        putStrLn "\t--clean list cleaning"
                        putStrLn "\tn order of the sequence"
                        putStrLn "\ta alphabet [def: \"01\"]"
        else (launcher (transform_opt x))
