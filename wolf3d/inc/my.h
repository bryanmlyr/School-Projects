/*
** my.h for my.h in /home/r00t/Desktop/graphics/wolf3d
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Fri Dec 23 17:57:06 2016 r00t
** Last update Mon Jan 23 20:22:21 2017 r00t
*/

#ifndef MY_H_
#define MY_H_

#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct	s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

sfColor			colors(int r, int g, int b, int a);
sfVector2f		move_forward(sfVector2f pos
				     , float direction, float distance);
void			my_put_pixel(t_my_framebuffer *frambuffer
				     , int x, int y, sfColor color);
t_my_framebuffer        *create_pixel_buffer(int width, int height);
float			raycast(sfVector2f pos, float direction
				, int **map, sfVector2i mapSize);
void			my_draw_line(t_my_framebuffer *framebuffer
				     , sfVector2i from, sfVector2i to
				     , sfColor color);
int			**fullmap(int ac, char **av);
sfVector2i		my_2D(int x, int y);
sfVector2f		my_2DF(float x, float y);
void			draw_wall(t_my_framebuffer *frm, float anglefov
				  , int **map, sfVector2f pos_pla);

#endif /* MY_H_ */
