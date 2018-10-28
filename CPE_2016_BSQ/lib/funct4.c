/*
** funct4.c for func4.c in /home/r00t/Desktop/CPE/CPE_2016_BSQ/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Fri Dec 16 13:55:31 2016 r00t
** Last update Fri Dec 16 15:24:14 2016 r00t
*/

#include "../inc/my.h"

void	check(int ac, char **av, d_liste *l, int x)
{
  while (x != nbligne(map(ac, av)) + 1)
    {
      if (checksquare(l->s, 1, 0, x) == 1)
	{
	  l->pos[0] = 1;
	  l->pos[1] = 0;
	  l->pos[2] = x;
	  x = nbligne(map(ac, av) + 1);
	}
      x++;
    }
}

void	check1(int ac, char **av, d_liste *l, int x)
{
  while (x != tligne(map(ac, av)) + 1)
    {
      if (checksquare(l->s, 1, x, 0) == 1)
	{
	  l->pos[0] = 1;
	  l->pos[1] = x;
	  l->pos[2] = 0;
	  x = tligne(map(ac, av));
	}
      x++;
    }
}

int	checkline(int ac, char **av, d_liste *l)
{
  int	x;

  x = 0;
  if (tligne(map(ac, av)) == 1)
    {
      check(ac, av, l, x);
      printtab(drawsq(l , l->s), 0);
      return (1);
    }
  if (nbligne(map(ac, av)) == 1)
    {
      check1(ac, av, l, x);
      printtab(drawsq(l, l->s), 0);
      return (2);
    }
  return (0);
}
