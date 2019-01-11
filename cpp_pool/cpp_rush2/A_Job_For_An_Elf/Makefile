##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	=	santa

SRC	=	littlepony.cpp			\
		object.cpp			\
		teddy.cpp			\
		toy.cpp				\
		main.cpp			\
		GiftPaper.cpp			\
		Wrap.cpp			\
		Box.cpp				\
		PapaXmasConveyorBelt.cpp	\
		PapaXmasTable.cpp		\
		Elf.cpp

OBJ	=	$(SRC:.cpp=.o)

CFLAGS	=	-std=c++11 -W -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
