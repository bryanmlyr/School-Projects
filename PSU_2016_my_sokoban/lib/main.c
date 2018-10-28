/*
** main.c for main in /home/r00t/Desktop/psu/PSU_2016_my_sokoban/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Sun Dec 11 21:25:39 2016 r00t
** Last update Sun Dec 18 10:49:01 2016 r00t
*/

#include "../inc/my.h"

void	usage_h()
{
  my_putstr("USAGE\n\t   ./my_sokoban map\n\nDESCRIPTION\n\t   map\tfile ");
  my_putstr("representing the warehouse map, containing '#' for walls,\n\t");
  my_putstr("\t   'P' for the player, 'X' for boxes and 'O' ");
  my_putstr("for storage locations.\n");
  exit(0);
}

int	main(int ac, char **av)
{
  if (ac != 2)
    exit (84);
  if (av[1][0] == '-' && av[1][1] == 'h')
    usage_h();
  premain(ac, av);
}
