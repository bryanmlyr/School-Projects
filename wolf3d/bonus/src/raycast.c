/*
** raycast.c for raycast.c in /home/r00t/Desktop/graphics/bswolf3d/src
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Mon Dec 19 13:22:17 2016 r00t
** Last update Fri Dec 30 15:59:14 2016 r00t
*/

#include "../inc/my.h"

sfVector2f	move(sfVector2f pos, float direction, float distance)
{
  sfVector2f	out;

  out.x = pos.x + (distance * cos(direction * M_PI / 180));
  out.y = pos.y + (distance * sin(direction * M_PI / 180));
  return (out);
}

float	raycast(sfVector2f pos, float direction
		, int **map, sfVector2i mapSize)
{
  sfVector2f posf;
  float	lon;

  lon = 0;
  posf.x = pos.x;
  posf.y = pos.y;
  while (map[(int)(posf.y)][(int)(posf.x)] != 1)
    {
      posf = move(posf, direction, lon);
      lon += 0.00001;
    }
  lon = sqrtf(powf((posf.x - pos.x), 2) + powf((posf.y - pos.y), 2));
  if (lon == -0.000000)
    lon = 0;
  return (lon);
}
