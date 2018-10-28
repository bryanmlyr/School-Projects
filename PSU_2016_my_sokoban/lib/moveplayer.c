/*
** moveplayer.c for moveplayer in /home/r00t/Desktop/PSU/PSU_2016_my_sokoban/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Thu Dec 15 20:18:11 2016 r00t
** Last update Thu Dec 15 20:32:06 2016 r00t
*/

#include "../inc/my.h"

char	**move2(char **out, d_struct *data, int pn)
{
  if (pn == 2 && out[data->d[0]][data->d[1] - 1] != '#'
      && out[data->d[0]][data->d[1] - 1] != 'X')
    {
      out[data->d[0]][data->d[1]] = ' ';
      out[data->d[0]][data->d[1] - 1] = 'P';
      return (out);
    }
  if (pn == 3 && out[data->d[0]][data->d[1] + 1] != '#'
      && out[data->d[0]][data->d[1] + 1] != 'X')
    {
      out[data->d[0]][data->d[1]] = ' ';
      out[data->d[0]][data->d[1] + 1] = 'P';
      return (out);
    }
  return (out);
}

char	**moveplayer(char **map, d_struct *data, int pn)
{
  char	**out;

  out = map;
  if (pn == 0 && out[data->d[0] - 1][data->d[1]] != '#'
      && out[data->d[0] - 1][data->d[1]] != 'X')
    {
      out[data->d[0]][data->d[1]] = ' ';
      out[data->d[0] - 1][data->d[1]] = 'P';
    }
  if (pn == 1 && out[data->d[0] + 1][data->d[1]] != '#'
      && out[data->d[0] + 1][data->d[1]] != 'X')
    {
      out[data->d[0]][data->d[1]] = ' ';
      out[data->d[0] + 1][data->d[1]] = 'P';
    }
  out = move2(out, data, pn);
  return (out);
}
