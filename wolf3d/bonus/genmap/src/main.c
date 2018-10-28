/*
** main.c for genmap in /home/r00t/Desktop/graphics/wolfbonus/genmap
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Thu Dec 29 16:54:16 2016 r00t
** Last update Fri Dec 30 15:26:11 2016 r00t
*/

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_var
{
  char	*out;
  int	a;
  int	x;
  int	y;
  int	z;
  int	random;
}		d_var;

int	my_putstr(char *str);

int	my_getnbr(char *str);

void	exitstat(int ac)
{
  if (ac != 4)
    {
      my_putstr("Une erreur s'est produite !!!\n");
      my_putstr("- av[1] = Hauteur de la map !\n");
      my_putstr("- av[2] = Longueur d'une ligne !\n");
      my_putstr("- av[3] = Densité plus c'est faible ");
      my_putstr("plus il y'a de murs !\n");
      my_putstr("- /!\\ Attention les cartes de peuvents etres seulement");
      my_putstr("rectangulaire /!\\\n");
      exit(84);
    }
}

void	pre1(d_var *v, char **av)
{
  v->a = -1;
  while (++v->a != my_getnbr(av[2]))
    v->out[v->z++] = '1';
  v->out[v->z++] = '\n';
  while (v->x != my_getnbr(av[1]) - 2)
    {
      v->y = 0;
      v->out[v->z++] = '1';
      while (v->y != my_getnbr(av[2]) - 2)
	{
	  if (rand() % my_getnbr(av[3]) != 0)
	    v->out[v->z++] = '0';
	  else
	    v->out[v->z++] = '1';
	  v->y++;
	}
      v->out[v->z++] = '1';
      v->out[v->z++] = '\n';
      v->x++;
    }
}

void	pre2(d_var *v, char **av)
{
  v->a = -1;
  while (++v->a != my_getnbr(av[2]))
    v->out[v->z++] = '1';
  v->out[v->z++] = '\n';
  v->random = rand() % my_getnbr(av[2]) * my_getnbr(av[1]);
  while (v->out[v->random] != '1' && v->out[v->random] != '\n')
    {
      if (v->out[v->random] == '0')
	v->out[v->random] = '8';
      v->random = rand() % my_getnbr(av[2]) * my_getnbr(av[1]);
    }
}

int	main(int ac, char **av)
{
  d_var	*v;

  exitstat(ac);
  v = malloc(sizeof(*v));
  v->x = 0;
  v->z = 0;
  v->a = -1;
  v->out = malloc(sizeof(char *) * (my_getnbr(av[1]) * my_getnbr(av[2])));
  pre1(v, av);
  pre2(v, av);
  my_putstr(v->out);
}
