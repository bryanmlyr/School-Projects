SRC	=	main.c		\
		ftp_protocols.c	\
		init.c		\
		login.c		\
		moves.c		\
		transfert.c	\
		utils.c		\
		commands.c	\
		list.c

NAME	=	server

OBJS	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
		gcc -o $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
