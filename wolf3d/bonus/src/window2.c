/*
** window2.c for window2 in /home/r00t/Desktop/graphics/wolfbonus/src
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Fri Dec 30 14:22:02 2016 r00t
** Last update Fri Dec 30 15:35:40 2016 r00t
*/

#include "../inc/my.h"

sfVector2i	my_2D(int x, int y)
{
  sfVector2i out;

  out.x = x;
  out.y = y;
  return (out);
}

sfVector2f	my_2DF(float x, float y)
{
  sfVector2f	out;

  out.x = x;
  out.y = y;
  return (out);
}

void	coordxy(char **map, t_coord *coord)
{
  int	x;
  int	y;

  y = 0;
  while (map[y])
    {
      x = 0;
      while (map[y][x] != '\n')
	{
	  if (map[y][x] == '8')
	    {
	      coord->x = y + 0.5;
	      coord->y = x + 0.5;
	    }
	  x++;
	}
      x++;
      y++;
    }
}

void	set_coord(t_coord *coord, char **map)
{
  coord->mode.bitsPerPixel = 32;
  coord->mode.width = 1280;
  coord->mode.height = 720;
  coord->texture = sfTexture_create(1280, 720);
  coord->sprite = sfSprite_create();
  coord->frm = create_pixel_buffer(1280, 720);
  coord->window = sfRenderWindow_create(coord->mode, "wolf3D"
  , sfResize | sfClose, NULL);
  sfSprite_setTexture(coord->sprite, coord->texture, sfTrue);
  coord->x = 1.5;
  coord->y = 1.5;
  coordxy(map, coord);
  coord->z = 60;
}
