/*
** func3.c for func3 in /home/r00t/Desktop/PSU/PSU_2016_my_sokoban/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Thu Dec 15 19:54:10 2016 r00t
** Last update Sun Dec 18 19:33:38 2016 r00t
*/

#include "../inc/my.h"

void	prepare(char **s, d_struct *data, d_struct *poscoins)
{
  clear();
  refresh();
  find_player1(s, data);
  findcoinsarr(s, data, poscoins);
}

void	printalltab(char **tab)
{
  int	x;

  x = 0;
  while (tab[x])
    {
      my_putstr(tab[x]);
      x++;
    }
}

void	printwtab(char **tab)
{
  int	x;

  x = 0;
  while (tab[x])
    {
      printw("%s", tab[x]);
      x++;
    }
}

char	**keys1(char **s, d_struct *data, d_struct *poscoins, int key)
{
  if (key == KEY_LEFT)
    {
      prepare(s, data, poscoins);
      s = moveplayer(s, data, 2);
      s = pushcase(s, data, 2);
      s = replacecoins(s, poscoins);
      s = mappoint(tabmap(map(data->ac, data->av)), s);
      printwtab(s);
      return (s);
    }
  if (key == KEY_RIGHT)
    {
      prepare(s, data, poscoins);
      s = moveplayer(s, data, 3);
      s = pushcase(s, data, 3);
      s = replacecoins(s, poscoins);
      s = mappoint(tabmap(map(data->ac, data->av)), s);
      printwtab(s);
      return (s);
    }
  return (s);
}

char	**keys2(char **s, d_struct *data, d_struct *poscoins, int key)
{
  if (key == KEY_UP)
    {
      prepare(s, data, poscoins);
      s = moveplayer(s, data, 0);
      s = pushcase(s, data, 0);
      s = replacecoins(s, poscoins);
      s = mappoint(tabmap(map(data->ac, data->av)), s);
      printwtab(s);
      return (s);
    }
  if (key == KEY_DOWN)
    {
      prepare(s, data, poscoins);
      s = moveplayer(s, data, 1);
      s = pushcase(s, data, 1);
      s = replacecoins(s, poscoins);
      s = mappoint(tabmap(map(data->ac, data->av)), s);
      printwtab(s);
      return (s);
    }
  return (s);
}
