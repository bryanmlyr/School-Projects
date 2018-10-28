/*
** draw_ray.c for draw_ray.c in /home/r00t/Desktop/graphics/wolf3d/src
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Fri Dec 23 18:53:56 2016 r00t
** Last update Tue Dec 27 14:34:09 2016 r00t
*/

#include "../inc/my.h"

typedef	struct	s_vardrw
{
  sfVector2i	mapsize;
  int		lineh;
  int		strd;
  int		endd;
  int		x;
  float		save;
}		t_vardrw;

sfColor		colors(int r, int g, int b, int a)
{
  sfColor	out;

  out.r = r;
  out.g = g;
  out.b = b;
  out.a = a;
  return (out);
}

void	draw_wall(t_my_framebuffer *frm, float anglefov
		  , int **map, sfVector2f pos_pla)
{
  t_vardrw	drw;

  drw.x = -1;
  drw.save = anglefov + 30;
  while (++drw.x != 1280)
    {
      drw.lineh = (int) 720 / (raycast(pos_pla, anglefov, map, drw.mapsize)
      * cos((drw.save - anglefov) * M_PI / 180));
      drw.strd = -drw.lineh / 2 + 720 / 2;
      if (drw.strd < 0)
	drw.strd = 0;
      drw.endd = drw.lineh / 2 + 720 / 2;
      if (drw.endd >= 720)
	drw.endd = 720 - 1;
      my_draw_line(frm, my_2D(drw.x, drw.strd), my_2D(drw.x, drw.endd)
      , colors(149, 165, 166, 100));
      my_draw_line(frm, my_2D(drw.x, drw.strd), my_2D(drw.x, 0)
      , colors(52, 73, 94, 100));
      my_draw_line(frm, my_2D(drw.x, drw.endd), my_2D(drw.x, 720)
      , colors(30, 130, 76, 100));
      anglefov+=0.046875;
    }
}
