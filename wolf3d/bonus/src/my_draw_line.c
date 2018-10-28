/*
** main.c for wireframe in /home/r00t/Desktop/graphics/wireframe
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Sun Dec  4 15:47:44 2016 r00t
** Last update Mon Dec 26 23:46:51 2016 r00t
*/

#include "../inc/my.h"

typedef	struct	s_var
{
  int dx;
  int sx;
  int dy;
  int sy;
  int err;
  int e2;
  int x;
}		d_var;

int	my_abs(int i)
{
  if (i < 0)
    return (i *-1);
  return (i);
}

void	swap(int *x, int *y)
{
  int	save;

  save = *x;
  *x = *y;
  *y = save;
}

void	my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from
		     , sfVector2i to, sfColor color)
{
  d_var	v;

  v.x = 0;
  v.dx = my_abs(to.x - from.x);
  v.sx = from.x<to.x ? 1 : -1;
  v.dy = my_abs(to.y - from.y);
  v.sy = from.y<to.y ? 1 : -1;
  v.err = (v.dx>v.dy ? v.dx : -v.dy) / 2;
  while (v.x != 1)
    {
      my_put_pixel(framebuffer, from.x, from.y, color);
      if (from.x==to.x && from.y==to.y)
	v.x = 1;
      v.e2 = v.err;
      if (v.e2 > -v.dx)
	{
	  v.err -= v.dy;
	  from.x += v.sx;
	}
      if (v.e2 < v.dy)
	{
	  v.err += v.dx;
	  from.y += v.sy;
	}
    }
}
