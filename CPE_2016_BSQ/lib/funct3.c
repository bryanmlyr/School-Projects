/*
** funct3.c for funct 3 in /home/r00t/Desktop/CPE/CPE_2016_BSQ/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Fri Dec 16 16:13:41 2016 r00t
** Last update Fri Dec 16 16:14:29 2016 Bryan Maloyer
*/

#include "../inc/my.h"

void	findbigsquare(d_liste *l, int ac, char **av)
{
  l->a = 0;
  while (l->z != (l->e - l->a))
    {
      l->y = 0;
      while (l->y != l->x)
	{
	  if (checksquare(l->s, l->a, l->z, l->y) == 1 && l->b == 0)
	    {
	      l->pos[0] = l->a;
	      l->pos[1] = l->z;
	      l->pos[2] = l->y;
	      l->z = 0;
	      l->y = 0;
	      l->b = 1;
	      l->d++;
	      l->a++;
	    }
	  if (checksquare(l->s, l->a, l->z, l->y) != 1 && l->b != 0)
	    l->b = 0;
	  l->y++;
	}
      l->z++;
    }
}

char	**drawsq(d_liste *l, char **tabl)
{
  int	x;
  int	y;
  char	**tab;
  int	save;

  x = 0;
  y = 0;
  save = l->pos[2];
  tab = tabl;
  while (y != l->pos[0])
    {
      x = 0;
      l->pos[2] = save;
      while (x != l->pos[0])
	{
	  tab[l->pos[1]][l->pos[2]] = 'x';
	  l->pos[2]++;
	  x++;
	}
      l->pos[1]++;
      y++;
    }
  return (tab);
}

void	printtab(char **tab, int z)
{
  int	x;

  x = z;
  while (tab[x])
    {
      my_putstr(tab[x]);
      my_putstr("\n");
      x++;
    }
}

int	check_is_empty(char *map, d_liste *l)
{
  int	x;

  x = 0;
  while (map[x])
    {
      if (map[x] == 'o')
	return (-1);
      x++;
    }
  l->pos[0] = l->e - 1;
  l->pos[1] = 0;
  l->pos[2] = 0;
  printtab(drawsq(l, l->s), 0);
  return (0);
}
