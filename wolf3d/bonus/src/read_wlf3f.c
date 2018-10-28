/*
** read_wlf3f.c for readfile in /home/r00t/Desktop/graphics/wolf3d/src
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Fri Dec 23 18:47:40 2016 r00t
** Last update Fri Dec 30 14:11:06 2016 r00t
*/

#include "../inc/my.h"

typedef struct	s_var
{
  int	fd;
  int	x;
  char	*src;
  int	**out;
  int	a;
  int	b;
}		t_var;

char	**map1(char **av)
{
  t_var	v;
  int	a;
  int	x;
  int	y;
  char	**out;

  x = y = a = 0;
  v.fd = open(av[1], O_RDONLY);
  v.src = malloc(sizeof(char *) * 2048);
  read(v.fd, v.src, 2048);
  out = malloc(sizeof(char **) * 2048);
  while (v.src[a])
    {
      x = 0;
      out[y] = malloc(sizeof(char *) * 2048);
      while (v.src[a] != '\n')
	{
	  out[y][x++] = v.src[a];
	  a++;
	}
      my_strcat(out[y], "\n");
      a++;
      y++;
    }
  return (out);
}

int	**fullmap(int ac, char **av)
{
  t_var	v;

  v.x = 0;
  v.a = 0;
  v.fd = open(av[1], O_RDONLY);
  v.src = malloc(sizeof(char *) * 2048);
  read(v.fd, v.src, 2048);
  v.out = malloc(sizeof(int **) * 2048);
  while (v.src[v.x])
    {
      v.out[v.a] = malloc(sizeof(int *) * 2048);
      v.b = 0;
      while (v.src[v.x] != '\n')
	{
	  v.out[v.a][v.b] = v.src[v.x] - 48;
	  v.b++;
	  v.x++;
	}
      v.a++;
      v.x++;
    }
  return (v.out);
}
