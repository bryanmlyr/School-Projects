/*
** pushcases.c for pushcase.c in /home/r00t/Desktop/PSU/PSU_2016_my_sokoban/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Thu Dec 15 20:18:21 2016 r00t
** Last update Thu Dec 15 20:35:02 2016 r00t
*/

#include "../inc/my.h"

char	**push1(char **out, d_struct *data, int pn)
{
  if (pn == 0 && out[data->d[0] - 1][data->d[1]] != '#')
    {
      if (out[data->d[0] - 1][data->d[1]] == 'X'
	  && out[data->d[0] - 2][data->d[1]] != '#'
	  && out[data->d[0] - 2][data->d[1]] != 'X')
	{
	  out[data->d[0]][data->d[1]] = ' ';
	  out[data->d[0] - 1][data->d[1]] = 'P';
	  out[data->d[0] - 2][data->d[1]] = 'X';
	}
      return (out);
    }
  if (pn == 1 && out[data->d[0] + 1][data->d[1]] != '#')
    {
      if (out[data->d[0] + 1][data->d[1]] == 'X'
	  && out[data->d[0] + 2][data->d[1]] != '#'
	  && out[data->d[0] + 2][data->d[1]] != 'X')
	{
	  out[data->d[0]][data->d[1]] = ' ';
	  out[data->d[0] + 1][data->d[1]] = 'P';
	  out[data->d[0] + 2][data->d[1]] = 'X';
	}
      return (out);
    }
  return (out);
}

char	**push2(char **out, d_struct *data, int pn)
{
  if (pn == 2 && out[data->d[0]][data->d[1] - 1] != '#')
    {
      if (out[data->d[0]][data->d[1] - 1] == 'X'
	  && out[data->d[0]][data->d[1] - 2] != '#'
	  && out[data->d[0]][data->d[1] - 2] != 'X')
	{
	  out[data->d[0]][data->d[1]] = ' ';
	  out[data->d[0]][data->d[1] - 1] = 'P';
	  out[data->d[0]][data->d[1] - 2] = 'X';
	}
      return (out);
    }
  if (pn == 3 && out[data->d[0]][data->d[1] + 1] != '#')
    {
      if (out[data->d[0]][data->d[1] + 1] == 'X'
	  && out[data->d[0]][data->d[1] + 2] != '#'
	  && out[data->d[0]][data->d[1] + 2] != 'X')
	{
	  out[data->d[0]][data->d[1]] = ' ';
	  out[data->d[0]][data->d[1] + 1] = 'P';
	  out[data->d[0]][data->d[1] + 2] = 'X';
	}
      return (out);
    }
  return (out);
}

char	**pushcase(char **map, d_struct *data, int pn)
{
  char	**out;

  out = map;
  out = push1(out, data, pn);
  out = push2(out, data, pn);
  return (out);
}
