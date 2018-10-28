/*
** move_foward.c for mvfrwd in /home/r00t/Desktop/graphics/bswolf3d/src
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Mon Dec 19 10:55:09 2016 r00t
** Last update Sun Dec 25 11:31:05 2016 r00t
*/

#include "../inc/my.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  sfVector2f	out;

  out.x = pos.x + (distance * cos(direction * M_PI / 180));
  out.y = pos.y + (distance * sin(direction * M_PI / 180));
  return (out);
}
