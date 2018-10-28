/*
** minimap.c for minimap.c in /home/r00t/Desktop/graphics/wolfbonus/src
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Fri Dec 30 14:06:52 2016 r00t
** Last update Mon Jan 23 20:20:48 2017 r00t
*/

#include "../inc/my.h"

typedef	struct	s_varmin
{
  int	x;
  int	y;
  int	a;
  int	b;
  int	c;
}		t_varmin;

void		crosshair(t_my_framebuffer *frm, sfColor color)
{
  my_draw_line(frm, my_2D(635, 359), my_2D(645, 359), color);
  my_draw_line(frm, my_2D(635, 360), my_2D(645, 360), color);
  my_draw_line(frm, my_2D(635, 361), my_2D(645, 361), color);
  my_draw_line(frm, my_2D(639, 355), my_2D(639, 365), color);
  my_draw_line(frm, my_2D(640, 355), my_2D(640, 365), color);
  my_draw_line(frm, my_2D(641, 355), my_2D(641, 365), color);
}

void	draw_min(t_my_framebuffer *frm, t_coord *coord)
{
  my_draw_line(frm, my_2D((int)((coord->x - 0.025)* 25)
  , (int)(coord->y * 25))
  , my_2D((int)((coord->x + 0.025) * 25), (int)(coord->y * 25)), sfBlue);
  my_draw_line(frm, my_2D((int)((coord->x - 0.05)* 25)
  , (int)(coord->y * 25))
  , my_2D((int)((coord->x + 0.05) * 25), (int)(coord->y * 25)), sfBlue);
  my_draw_line(frm, my_2D((int)((coord->x - 0.05)* 25)
  , (int)((coord->y - 0.025) * 25))
  , my_2D((int)((coord->x + 0.05) * 25), (int)((coord->y - 0.025) * 25))
  , sfBlue);
  my_draw_line(frm, my_2D((int)((coord->x - 0.05)* 25)
  , (int)((coord->y - 0.05) * 25))
  , my_2D((int)((coord->x + 0.05) * 25), (int)((coord->y - 0.05) * 25))
  , sfBlue);
}

void		minmappos(char **map, t_my_framebuffer *frm, t_varmin *var)
{
  int	z;

  if (map[var->y][var->x] == '1')
    {
      z = -1;
      while (++z != 25)
	my_draw_line(frm, my_2D(var->a + z, var->b)
      , my_2D(var->a + z, var->c), sfBlack);
    }
  if (map[var->y][var->x] == '0' || map[var->y][var->x] == '8')
    {
      z = -1;
      while (++z != 25)
	my_draw_line(frm, my_2D(var->a + z, var->b)
      , my_2D(var->a + z, var->c), sfWhite);
    }

}

void		minimap(t_my_framebuffer *frm, char **map, t_coord *coord)
{
  t_varmin	*var;

  var = malloc(sizeof(*var));
  var->y = 0;
  var->a = 0;
  var->b = 0;
  var->c = 25;
  while (map[var->y])
    {
      var->x = 0;
      while (map[var->y][var->x] != '\n')
	{
	  minmappos(map, frm, var);
	  draw_min(frm, coord);
	  var->b+=25;
	  var->c+=25;
	  var->x++;
	}
      var->a+=25;
      var->b = 0;
      var->c = 25;
      var->x++;
      var->y++;
    }
}
