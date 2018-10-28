/*
** my.h for my in /home/r00t/Desktop/PSU/PSU_2016_my_sokoban/inc
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Thu Dec 15 19:50:09 2016 r00t
** Last update Sun Dec 18 19:30:00 2016 r00t
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <curses.h>
#include <ncurses.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef struct	s_struct
{
  int	d[2];
  int	ac;
  char	**av;
}		d_struct;

typedef struct	s_liste
{
  int	x[2];
  struct s_liste *next;
}		d_liste;

void	my_putchar(char c);
void	my_putstr(char *s);
int	my_strlen(char *s);
char	*map(int ac, char **av);
char	**tabmap(char *map);
int	check_coins(char **tab);
void	print_tabx(char **tab, int x);
int	find_player1(char **tab, d_struct *data);
void	findcoinsarr(char **tab, d_struct *data, d_struct *poscoins);
char	**replacecoins(char **tab, d_struct *poscoins);
char	**moveplayer(char **map, d_struct *data, int pn);
char	**pushcase(char **map, d_struct *data, int pn);
void	printalltab(char **tab);
void	printwtab(char **tab);
char	*my_strcat(char *dest, char *src);
void	premain(int ac, char **av);
char	**keys1(char **s, d_struct *data, d_struct *poscoins, int key);
char	**keys2(char **s, d_struct *data, d_struct *poscoins, int key);
int	checkpos(char **mapcl, char **map);
void	pushtop(d_liste **p, int x, int y);
char	**mappoint(char **mapcl, char **map);

#endif /* MY_H_ */
