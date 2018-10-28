/*
** draw_ray.c for draw_ray.c in /home/r00t/Desktop/graphics/wolf3d/src
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Fri Dec 23 18:53:56 2016 r00t
** Last update Sun Jan  1 21:19:01 2017 r00t
*/

#include "../inc/my.h"

typedef	struct	s_vardrw
{
  sfVector2i	mapsize;
  int		lineh;
  int		strd;
  int		endd;
  int		x;
  float		fy;
  float		fx;
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

sfVector2f	mv(sfVector2f pos, float direction, float distance)
{
  sfVector2f	out;

  out.x = pos.x + (distance * cos(direction * M_PI / 180));
  out.y = pos.y + (distance * sin(direction * M_PI / 180));
  return (out);
}

float	ray(sfVector2f pos, float direction
		, int **map, t_vardrw *var)
{
  sfVector2f posf;
  float	lon;

  lon = 0;
  posf.x = pos.x;
  posf.y = pos.y;
  while (map[(int)(posf.y)][(int)(posf.x)] != 1)
    {
      posf = mv(posf, direction, lon);
      lon += 0.00001;
    }
  var->fx = posf.x;
  var->fy = posf.y;
  lon = sqrtf(powf((posf.x - pos.x), 2) + powf((posf.y - pos.y), 2));
  if (lon == -0.000000)
    lon = 0;
  return (lon);
}

void	draw(t_vardrw drw, t_my_framebuffer *frm, float ryc)
{
  my_draw_line(frm, my_2D(drw.x, drw.strd), my_2D(drw.x, drw.endd - 1)
  , colors(149 * ryc, 165 * ryc, 166 * ryc, 100));
  my_draw_line(frm, my_2D(drw.x, drw.endd - 1), my_2D(drw.x, drw.endd)
  , sfBlack);
  my_draw_line(frm, my_2D(drw.x, drw.strd), my_2D(drw.x, drw.strd + 1)
  , sfBlack);
  my_draw_line(frm, my_2D(drw.x, drw.strd), my_2D(drw.x, 0)
  , colors(52, 73, 94, 100));
  my_draw_line(frm, my_2D(drw.x, drw.endd), my_2D(drw.x, 720)
  , colors(30, 130, 76, 100));
}

void	draw_wall(t_my_framebuffer *frm, float anglefov
		  , int **map, sfVector2f pos_pla)
{
  t_vardrw	drw;
  t_vardrw	*var;
  float		ry;
  float		ryc;

  var = malloc(sizeof(*var));
  drw.x = -1;
  drw.save = anglefov + 30;
  while (++drw.x != 1280)
    {
      ry = ray(pos_pla, anglefov, map, var)
      * cos((drw.save - anglefov) * M_PI / 180);
      ryc = (ry + 0.5) * -0.1;
      if (ryc < -1.2)
	ryc = -1.2;
      drw.lineh = (int) 720 / ry;
      drw.strd = -drw.lineh / 2 + 720 / 2;
      if (drw.strd < 0)
	drw.strd = 0;
      drw.endd = drw.lineh / 2 + 720 / 2;
      if (drw.endd >= 720)
	drw.endd = 720 - 1;
      draw(drw, frm, ryc);
      anglefov+=0.046875;
    }
}
