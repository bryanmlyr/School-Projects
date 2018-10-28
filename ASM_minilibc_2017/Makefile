NAME		=	libasm.so

SRCS		=	strlen.asm	\
			strchr.asm	\
			memset.asm	\
			memcpy.asm	\
			strcmp.asm	\
			rindex.asm	\
			memmove.asm	\
			strpbrk.asm	\
			read.asm	\
			write.asm	\

RM		=	rm -f

OBJS		=	strlen.o	\
			strchr.o	\
			memset.o	\
			memcpy.o	\
			strcmp.o	\
			strncmp.o	\
			rindex.o	\
			memmove.o	\
			strpbrk.o	\
			read.o		\
			write.o		\

all:		$(NAME)

$(NAME):
		nasm -o strlen.o strlen.asm -f elf64
		nasm -o strchr.o strchr.asm -f elf64
		nasm -o memset.o memset.asm -f elf64
		nasm -o memcpy.o memcpy.asm -f elf64
		nasm -o strcmp.o strcmp.asm -f elf64
		nasm -o strncmp.o strncmp.asm -f elf64
		nasm -o rindex.o rindex.asm -f elf64
		nasm -o memmove.o memmove.asm -f elf64
		nasm -o strpbrk.o strpbrk.asm -f elf64
		nasm -o read.o read.asm -f elf64
		nasm -o write.o write.asm -f elf64
		ld -fPIC -shared -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all