/*
** main.c for mainc in /home/r00t/Desktop/elementary_programming/CPE_2016_BSQ/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Fri Dec  9 00:17:42 2016 r00t
** Last update Fri Dec 16 22:19:08 2016 r00t
*/

#include "../inc/my.h"

int	validmap(char *map)
{
  int	x;

  x = 0;
  while (map[x] != '\n')
    x++;
  x++;
  while (map[x])
    {
      if (map[x] != 'o' && map[x] != '.' && map[x] != '\n')
	return (-1);
      x++;
    }
  return (0);
}

int	checkculumone(char *map)
{
  int	x;

  x = 0;
  while (map[x] != '\n')
    x++;
  x++;
  while (map[x])
    {
      if (map[x] == '.')
	return (-1);
      x++;
    }
  return (0);
}

void	premain(int ac, char **av, d_liste *l)
{
  l->y = l->z = l->b = l->c = l->d = l->e = 0;
  l->s = maptod(map(ac, av));
  if (nbligne(map(ac, av)) <= tligne(map(ac, av)))
    {
      l->x = tligne(map(ac, av));
      l->e = nbligne(map(ac, av)) + 1;
    }
  else
    {
      l->x = nbligne(map(ac, av));
      l->e = tligne(map(ac, av)) + 1;
    }
}

int	main(int ac, char **av)
{
  d_liste	*l;

  if (ac != 2 || validmap(map(ac, av)) == -1)
    return (84);
  l = malloc(sizeof(d_liste));
  premain(ac, av, l);
  if (checkculumone(map(ac, av)) == 0)
    {
      printtab(maptod(map(ac, av)), 0);
      return (0);
    }
  if (check_is_empty(map(ac, av), l) == 0)
    return (0);
  if (checkline(ac, av, l) == 1)
    return (0);
  findbigsquare(l, ac, av);
  if (l->d == 0)
    printtab(maptod(map(ac, av)), 0);
  if (l->d != 0 && nbligne(map(ac, av)) != 1)
    printtab(drawsq(l, l->s), 0);
  return (0);
}
