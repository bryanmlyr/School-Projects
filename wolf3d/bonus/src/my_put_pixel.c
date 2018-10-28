/*
** my_put_pixel.c for wireframe in /home/r00t/Desktop/graphics/wireframe
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Sun Dec  4 16:13:43 2016 r00t
** Last update Sun Dec 25 11:31:24 2016 r00t
*/

#include "../inc/my.h"

void	my_put_pixel(t_my_framebuffer *frambuffer, int x, int y, sfColor color)
{
  frambuffer->pixels[(1280 * y + x) * 4] = color.r;
  frambuffer->pixels[(1280 * y + x) * 4 + 1] = color.g;
  frambuffer->pixels[(1280 * y + x) * 4 + 2] = color.b;
  frambuffer->pixels[(1280 * y + x) * 4 + 3] = color.a;
}
