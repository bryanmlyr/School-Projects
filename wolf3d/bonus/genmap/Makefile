SRC	=	src/main.c		\
		src/my_getnbr.c		\
		src/my_putchar.c	\
		src/my_putstr.c		\

COMP	=	$(SRC:.c=.o)

RM	=	rm -rf

NAME	=	gen

all:	$(COMP)
	gcc -o $(NAME) $(COMP)

clean:
	$(RM) $(COMP)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
