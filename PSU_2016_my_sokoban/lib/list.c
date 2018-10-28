/*
** list.c for list in /home/r00t/Desktop/PSU/PSU_2016_my_sokoban/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Sun Dec 18 00:49:29 2016 r00t
** Last update Sun Dec 18 10:59:16 2016 r00t
*/

#include "../inc/my.h"

d_liste		*check_linked_list(char **map)
{
  d_liste	*lnkls;
  int		x;
  int		y;

  lnkls = NULL;
  x = 0;
  y = 0;
  while (map[x])
    {
      y = 0;
      while (map[x][y])
	{
	  if (map[x][y] == 'O')
	    pushtop(&lnkls, x, y);
	  y++;
	}
      x++;
    }
  return (lnkls);
}

int	checkpos(char **mapcl, char **map)
{
  d_liste	*chkps;

  chkps = check_linked_list(mapcl);
  while (chkps != NULL)
    {
      if (map[chkps->x[0]][chkps->x[1]] != 'X')
	return (-1);
      chkps = chkps->next;
    }
  return (0);
}

char	**mappoint(char **mapcl, char **map)
{
  d_liste	*chkps;
  char		**mapout;

  chkps = check_linked_list(mapcl);
  mapout = map;
  while (chkps != NULL)
    {
      if (mapout[chkps->x[0]][chkps->x[1]] == ' ')
	mapout[chkps->x[0]][chkps->x[1]] = 'O';
      chkps = chkps->next;
    }
  return (mapout);
}
