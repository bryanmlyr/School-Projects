/*
** window.c for window in /home/r00t/Desktop/graphics/wolf3d
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Fri Dec 23 18:02:35 2016 r00t
** Last update Fri Jan 13 13:41:54 2017 r00t
*/

#include "../inc/my.h"

int	retpos(t_coord *coord)
{
  if (sfKeyboard_isKeyPressed(sfKeyZ)
  && coord->map[(int)(coord->x + 0.01)][(int)(coord->y)] != 1)
    coord->x+=0.01;
  if (sfKeyboard_isKeyPressed(sfKeyS)
  && coord->map[(int)(coord->x - 0.01)][(int)(coord->y)] != 1)
    coord->x-=0.01;
  if (sfKeyboard_isKeyPressed(sfKeyQ)
  && coord->map[(int)(coord->x)][(int)(coord->y + 0.01)] != 1)
    coord->y+=0.01;
  if (sfKeyboard_isKeyPressed(sfKeyD)
  && coord->map[(int)(coord->x)][(int)(coord->y - 0.01)] != 1)
    coord->y-=0.01;
  if (sfKeyboard_isKeyPressed(sfKeyLeft))
    coord->z-=1.25;
  if (sfKeyboard_isKeyPressed(sfKeyRight))
    coord->z+=1.25;
  if (sfKeyboard_isKeyPressed(sfKeyRight)
      || sfKeyboard_isKeyPressed(sfKeyLeft)
      || sfKeyboard_isKeyPressed(sfKeyD)
      || sfKeyboard_isKeyPressed(sfKeyQ)
      || sfKeyboard_isKeyPressed(sfKeyZ)
      || sfKeyboard_isKeyPressed(sfKeyS))
    return (1);
  else
    return (0);
}

void		pre(t_coord *coord, char **map)
{
  while (retpos(coord) == 1)
    {
      sfRenderWindow_clear(coord->window, sfTransparent);
      draw_wall(coord->frm, coord->z, coord->map
      , my_2DF(coord->y, coord->x));
      crosshair(coord->frm, colors(0, 0, 255, 100));
      minimap(coord->frm, map, coord);
      sfTexture_updateFromPixels(coord->texture
      , coord->frm->pixels, 1280, 720, 0, 0);
      sfRenderWindow_drawSprite(coord->window, coord->sprite, NULL);
      sfRenderWindow_display(coord->window);
    }
}

void		pre2(t_coord *coord)
{
  sfRenderWindow_clear(coord->window, sfTransparent);
  sfTexture_updateFromPixels(coord->texture
  , coord->frm->pixels, 1280, 720, 0, 0);
  sfRenderWindow_drawSprite(coord->window, coord->sprite, NULL);
  sfRenderWindow_display(coord->window);
}

int		main(int ac, char **av)
{
  sfEvent	event;
  sfMusic	*music;
  t_coord	*coord;
  char		**map;

  if (ac != 2)
    return (84);
  coord = malloc(sizeof(*coord));
  map = map1(av);
  coord->map = fullmap(ac, av);
  set_coord(coord, map);
  music = sfMusic_createFromFile("./src/music.ogg");
  sfMusic_play(music);
  while (sfRenderWindow_isOpen(coord->window))
    {
      while (sfRenderWindow_pollEvent(coord->window, &event))
	{
	  if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
	    sfRenderWindow_close(coord->window);
	  pre(coord, map);
	}
      pre2(coord);
    }
  sfRenderWindow_destroy(coord->window);
  return (0);
}
