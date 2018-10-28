/*
** utilis.c for utilis in /home/r00t/Desktop/graphics/wolf3d/src
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Tue Dec 27 20:53:49 2016 r00t
** Last update Tue Dec 27 20:54:44 2016 Bryan Maloyer
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
