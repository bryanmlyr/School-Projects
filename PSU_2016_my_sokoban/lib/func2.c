/*
** func2.c for func2 in /home/r00t/Desktop/PSU/PSU_2016_my_sokoban/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Thu Dec 15 19:53:00 2016 r00t
** Last update Thu Dec 15 20:10:37 2016 Bryan Maloyer
*/

#include "../inc/my.h"

int	check_coins(char **tab)
{
  int	x;
  int	y;
  int	z;

  x = 0;
  y = 0;
  z = 0;
  while (tab[x])
    {
      y = 0;
      while (tab[x][y] != '\n')
	{
	  if (tab[x][y] == 'O')
	    {
	      z++;
	      y++;
	    }
	  y++;
	}
      x++;
    }
  return (z);
}

void	print_tabx(char **tab, int x)
{
  int	c;

  c = -1;
  while (tab[x][c++] != '\n')
    my_putchar(tab[x][c]);
  my_putchar(tab[x][c]);
  return;
}

int	find_player1(char **tab, d_struct *data)
{
  int	a;
  int	b;
  int	c;

  a = b = c = 0;
  while (tab[a])
    {
      b = 0;
      while (tab[a][b] != '\n')
	{
	  if (tab[a][b] == 'P')
	    {
	      data->d[0] = a;
	      data->d[1] = b;
	      c++;
	      b++;
	    }
	  b++;
	}
      a++;
    }
  if (c >= 2)
    return (-1);
  else
    return (0);
}

char	**replacecoins(char **tab, d_struct *poscoins)
{
  char	**tabl;

  tabl = tab;
  if (tabl[poscoins->d[0]][poscoins->d[1]] == ' ')
    tabl[poscoins->d[0]][poscoins->d[1]] = 'O';
  return (tabl);
}
