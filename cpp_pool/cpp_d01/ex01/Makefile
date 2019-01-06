SRC	=	main.c		\
		menger.c

OBJ	=	$(SRC:.c=.o)

NAME	=	menger

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all