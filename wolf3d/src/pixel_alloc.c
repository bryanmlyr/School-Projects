/*
** pixel_alloc.c for pixel_alloc in /home/r00t/Desktop/graphics/wolf3d
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Fri Dec 23 18:01:08 2016 r00t
** Last update Tue Dec 27 20:51:08 2016 r00t
*/

#include "../inc/my.h"

t_my_framebuffer       	*create_pixel_buffer(int width, int height)
{
  t_my_framebuffer	*ret;
  int			i;

  i = 0;
  ret = malloc(sizeof(t_my_framebuffer));
  ret->pixels = malloc(width * height * 4 * sizeof(ret->pixels));
  while (i < width * height * 4)
    {
      ret->pixels[i] = 0;
      i++;
    }
  return (ret);
}
