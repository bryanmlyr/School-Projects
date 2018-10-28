/*
** my.h for my.h in /home/r00t/Desktop/CPE/CPE_2016_BSQ/inc
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Tue Dec 13 22:12:53 2016 r00t
** Last update Fri Dec 16 16:19:12 2016 r00t
*/

#ifndef MY_H_
# define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef	struct	s_liste
{
  char	**s;
  int	pos[3];
  int	x;
  int	a;
  int	y;
  int	z;
  int	b;
  int	c;
  int	d;
  int	e;
  int	f;
}		d_liste;

int     my_strlen(char *s);
char    *map(int ac, char **av);
char    **maptod(char *map);
int     tligne(char *save);
int     nbligne(char *save);
int     checksquare(char **map, int size, int h, int start);
void	my_putstr(char *s);
char	**drawsq(d_liste *l, char **tabl);
void	printtab(char **tab, int z);
int	checkline(int ac, char **av, d_liste *l);
void	findbigsquare(d_liste *l, int ac, char **av);
char	**drawsq(d_liste *l, char **tabl);
int	check_is_empty(char *map, d_liste *l);

#endif /* MY_H_ */
