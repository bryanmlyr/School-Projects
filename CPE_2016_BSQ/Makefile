OBJS	=	lib/funct1.c	\
		lib/funct2.c	\
		lib/funct3.c	\
		lib/funct4.c	\
		lib/main.c	\

COMP	=	$(OBJS:.c=.o)

RM	=	rm -rf

CFLAGS	=	-O3 -W -I.

NAME	=	bsq

all:	$(COMP)
	gcc -o $(NAME) $(CFLAGS) $(COMP)

clean:
	$(RM) $(COMP)

fclean: clean
	$(RM) $(NAME)

re: fclean all
