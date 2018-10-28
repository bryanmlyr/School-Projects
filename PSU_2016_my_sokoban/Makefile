OBJS	=	lib/func1.c		\
		lib/func2.c		\
		lib/func3.c		\
		lib/func4.c		\
		lib/my_strcat.c		\
		lib/findcoins.c		\
		lib/main.c		\
		lib/moveplayer.c	\
		lib/pushcases.c		\
		lib/functlist.c		\
		lib/list.c		\

COMP	=	$(OBJS:.c=.o)

RM	=	rm -rf

CFLAGS	=	-lncurses -W -I.

NAME	=	my_sokoban

all:	$(COMP)
	gcc -o $(NAME) $(COMP) $(CFLAGS)

clean:
	$(RM) $(COMP)

fclean: clean
	$(RM) $(NAME)

re: fclean all
