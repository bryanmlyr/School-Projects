##
## Makefile for makefile in /home/r00t/Desktop/graphics/wolf3d
## 
## Made by r00t
## Login   <r00t@epitech.net>
## 
## Started on  Fri Dec 23 21:20:19 2016 r00t
## Last update Fri Dec 30 17:59:31 2016 r00t
##

SRC	=	src/draw_ray.c		\
		src/move_forward.c	\
		src/my_draw_line.c	\
		src/my_put_pixel.c	\
		src/pixel_alloc.c	\
		src/read_wlf3f.c	\
		src/window.c		\
		src/window2.c		\
		src/raycast.c		\
		src/my_strcat.c		\
		src/minimap.c		\

COMP	=	$(SRC:.c=.o)

RM	=	rm -rf

CFLAGS	=	-O3 -lm -lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-system -I./inc/

NAME	=	wolf3d

all:	$(COMP)	
	gcc -o $(NAME) $(COMP) $(CFLAGS)

clean:
	$(RM) $(COMP)

fclean: clean
	$(RM) $(NAME)

re: fclean all
