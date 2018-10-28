/*
** func1.c for func1 in /home/r00t/Desktop/PSU/PSU_2016_my_sokoban/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Thu Dec 15 19:52:15 2016 r00t
** Last update Thu Dec 15 19:56:04 2016 Bryan Maloyer
*/

#include "../inc/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *s)
{
  int	x;

  x = 0;
  while (s[x])
    {
      my_putchar(s[x]);
      x++;
    }
}

int	my_strlen(char *s)
{
  int	x;

  x = 0;
  while (s[x])
    x++;
  return (x);
}

char	*map(int ac, char **av)
{
  int	rd;
  char	*s;

  s = malloc(sizeof(char *) * 1024);
  rd = open(av[1], O_RDONLY);
  read(rd, s, 1024);
  my_strcat(s, "\n");
  return (s);
}

char	**tabmap(char *map)
{
  char	**out;
  int	x;
  int	a;
  int	b;

  x = 0;
  a = 0;
  b = 0;
  out = malloc(sizeof(char **) * my_strlen(map));
  while (map[x])
    {
      a = 0;
      out[b] = malloc(sizeof(char *) * my_strlen(map));
      while (map[x] != '\n')
	{
	  out[b][a] = map[x];
	  a++;
	  x++;
	}
      out[b][a] = map[x];
      b++;
      x++;
    }
  return (out);
}
