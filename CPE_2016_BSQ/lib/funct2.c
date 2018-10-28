/*
** funct2.c for funct2 in /home/r00t/Desktop/CPE/CPE_2016_BSQ/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Tue Dec 13 22:08:35 2016 r00t
** Last update Thu Dec 15 17:45:50 2016 r00t
*/

#include "../inc/my.h"

int	tligne(char *save)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (save[x] != '\n')
    {
      if (save[x] >= '0' && save[x] <= '9')
	y = (y * 10) + (save[x] - 48);
      x++;
    }
  return (y);
}

int	nbligne(char *save)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (save[x] != '\n')
    x++;
  x++;
  while (save[x] != '\n')
    {
      x++;
      y++;
    }
  return (y);
}

int	checksquare(char **map, int size, int h, int start)
{
  int	a;
  int	x;
  int	y;
  int	z;

  a = start;
  x = y = z = 0;
  while (x != size)
    {
      y = 0;
      a = start;
      while (y != size)
	{
	  if (map[h][a] == '.')
	    z++;
	  a++;
	  y++;
	}
      h++;
      x++;
    }
  if (z == size * size)
    return (1);
  else
    return (0);
}
