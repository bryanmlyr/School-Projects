##
## EPITECH PROJECT, 2018
## lemipc
## File description:
## makefile
##

SRC		=	src/main.c			\
			src/sem_operations.c		\
			src/shm_operations.c		\
			src/msg_operations.c		\
			src/display.c			\
			src/movement.c			\
			src/game.c			\
			src/enemy.c			\

NAME		=	lemipc

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS		=	-W -Wall -Wextra -I./inc

RM		=	rm -f

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
