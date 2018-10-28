/*
** funct1.c for funct1 in /home/r00t/Desktop/CPE/CPE_2016_BSQ/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Tue Dec 13 22:07:30 2016 r00t
** Last update Thu Dec 15 17:43:28 2016 r00t
*/

#include "../inc/my.h"

void	my_putchar(char s)
{
  write(1, &s, 1);
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
  struct stat	sb;
  int		op;
  int		buffer;
  char		*save;

  op = buffer = 0;
  stat(av[1], &sb);
  buffer = sb.st_size;
  op = open(av[1], O_RDONLY);
  save = malloc(sizeof(char *) * buffer);
  read(op, save, buffer);
  close(op);
  return (save);
}

char	**maptod(char *map)
{
  char	**out;
  int	x;
  int	a;
  int	b;

  a = b = x = 0;
  out = malloc(sizeof(char **) * my_strlen(map));
  while (map[x] != '\n')
    x++;
  x++;
  while (map[x])
    {
      out[a] = malloc(sizeof(char *) * my_strlen(map));
      b = 0;
      while (map[x] != '\n')
	{
	  out[a][b] = map[x];
	  x++;
	  b++;
	}
      a++;
      x++;
    }
  return (out);
}
