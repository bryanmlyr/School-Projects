##
## Makefile for makefile in /home/r00t/Desktop/graphics/wolf3d
## 
## Made by r00t
## Login   <r00t@epitech.net>
## 
## Started on  Fri Dec 23 21:20:19 2016 r00t
## Last update Sat Jan  7 13:34:10 2017 r00t
##

SRC	=	src/draw_ray.c		\
		src/move_forward.c	\
		src/my_draw_line.c	\
		src/my_put_pixel.c	\
		src/pixel_alloc.c	\
		src/read_wlf3f.c	\
		src/window.c		\
		src/raycast.c		\
		src/utilis.c		\

COMP	=	$(SRC:.c=.o)

RM	=	rm -rf

CFLAGS	=	-g -O3 -lm -lc_graph_prog -I./inc/

NAME	=	wolf3d

all:	$(COMP)	
	gcc -o $(NAME) $(COMP) $(CFLAGS)

clean:
	$(RM) $(COMP)

fclean: clean
	$(RM) $(NAME)

re: fclean all
