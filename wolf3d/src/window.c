/*
** window.c for window in /home/r00t/Desktop/graphics/wolf3d
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Fri Dec 23 18:02:35 2016 r00t
** Last update Fri Jan 13 13:37:38 2017 r00t
*/

#include "../inc/my.h"

typedef struct		s_coord
{
  sfVideoMode           mode;
  sfRenderWindow        *window;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfMusic		*music;
  t_my_framebuffer	*frm;
  float			x;
  float			y;
  float			z;
  int			**map;
}			t_coord;

void	set_coord(t_coord *coord)
{
  coord->mode.bitsPerPixel = 32;
  coord->mode.width = 1280;
  coord->mode.height = 720;
  coord->texture = sfTexture_create(1280, 720);
  coord->sprite = sfSprite_create();
  coord->frm = create_pixel_buffer(1280, 720);
  coord->frm->width = 1280;
  coord->frm->height = 720;
  coord->window = sfRenderWindow_create(coord->mode, "wolf3D"
  , sfResize | sfClose, NULL);
  sfSprite_setTexture(coord->sprite, coord->texture, sfTrue);
  coord->x = 1.5;
  coord->y = 1.5;
  coord->z = 60;
}

int	retpos(t_coord *coord)
{
  if (sfKeyboard_isKeyPressed(sfKeyZ))
    coord->x+=0.01;
  if (sfKeyboard_isKeyPressed(sfKeyS))
    coord->x-=0.01;
  if (sfKeyboard_isKeyPressed(sfKeyQ))
    coord->y+=0.01;
  if (sfKeyboard_isKeyPressed(sfKeyD))
    coord->y-=0.01;
  if (sfKeyboard_isKeyPressed(sfKeyLeft))
    coord->z-=1.75;
  if (sfKeyboard_isKeyPressed(sfKeyRight))
    coord->z+=1.75;
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

void		pre(t_coord *coord)
{
  sfRenderWindow_clear(coord->window, sfTransparent);
  draw_wall(coord->frm, coord->z, coord->map
  , my_2DF(coord->y, coord->x));
  sfTexture_updateFromPixels(coord->texture
  , coord->frm->pixels, 1280, 720, 0, 0);
  sfRenderWindow_drawSprite(coord->window, coord->sprite, NULL);
  sfRenderWindow_display(coord->window);
}

int		main(int ac, char **av)
{
  sfEvent	event;
  t_coord	*coord;

  if (ac != 2)
    return (84);
  coord = malloc(sizeof(*coord));
  coord->map = fullmap(ac, av);
  set_coord(coord);
  while (sfRenderWindow_isOpen(coord->window))
    {
      while (sfRenderWindow_pollEvent(coord->window, &event))
	{
	  if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
	    sfRenderWindow_close(coord->window);
	  while (retpos(coord) == 1)
	    pre(coord);
	}
      sfRenderWindow_clear(coord->window, sfTransparent);
      sfTexture_updateFromPixels(coord->texture
      , coord->frm->pixels, 1280, 720, 0, 0);
      sfRenderWindow_drawSprite(coord->window, coord->sprite, NULL);
      sfRenderWindow_display(coord->window);
    }
  sfRenderWindow_destroy(coord->window);
  return (0);
}
