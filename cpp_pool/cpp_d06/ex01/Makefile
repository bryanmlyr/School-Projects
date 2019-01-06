SRC		=	main.cpp	\

OBJ		=	$(SRC:.cpp=.o)

NAME		=	my_convert_temp

CPPFLAGS	=	-W -Werror -Wall -Wextra

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all