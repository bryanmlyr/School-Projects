SRC		=	src/main.c		\
			src/actions.c		\
			src/args.c

NAME		=	philo

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS		=	-W -Wall -Wextra -I./inc

RM		=	rm -f

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -L./ -lriceferee -lpthread

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all