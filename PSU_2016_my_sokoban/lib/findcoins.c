/*
** findcoins.c for findcoins.c in /home/r00t/Desktop/PSU/PSU_2016_my_sokoban/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Thu Dec 15 20:09:18 2016 r00t
** Last update Thu Dec 15 20:13:39 2016 r00t
*/

#include "../inc/my.h"

void	find1(char **tab, d_struct *data, d_struct *poscoins)
{
  if (tab[data->d[0] - 1][data->d[1]] == 'O')
    {
      poscoins->d[0] = data->d[0] - 1;
      poscoins->d[1] = data->d[1];
    }
  if (tab[data->d[0] + 1][data->d[1]] == 'O')
    {
      poscoins->d[0] = data->d[0] + 1;
      poscoins->d[1] = data->d[1];
    }
  if (tab[data->d[0]][data->d[1] - 1] == 'O')
    {
      poscoins->d[0] = data->d[0];
      poscoins->d[1] = data->d[1] - 1;
    }
  if (tab[data->d[0]][data->d[1] + 1] == 'O')
    {
      poscoins->d[0] = data->d[0];
      poscoins->d[1] = data->d[1] + 1;
    }
}

void	find2(char **tab, d_struct *data, d_struct *poscoins)
{
  if (tab[data->d[0] - 1][data->d[1]] == 'X'
      && tab[data->d[0] - 2][data->d[1]] == 'O')
    {
      poscoins->d[0] = data->d[0] - 2;
      poscoins->d[1] = data->d[1];
    }
  if (tab[data->d[0] + 1][data->d[1]] == 'X'
      && tab[data->d[0] + 2][data->d[1]] == 'O')
    {
      poscoins->d[0] = data->d[0] + 2;
      poscoins->d[1] = data->d[1];
    }
  if (tab[data->d[0]][data->d[1] - 1] == 'X'
      && tab[data->d[0]][data->d[1] - 2] == 'O')
    {
      poscoins->d[0] = data->d[0];
      poscoins->d[1] = data->d[1] - 2;
    }
  if (tab[data->d[0]][data->d[1] + 1] == 'X'
      && tab[data->d[0]][data->d[1] + 2] == 'O')
    {
      poscoins->d[0] = data->d[0];
      poscoins->d[1] = data->d[1] + 2;
    }
}

void	findcoinsarr(char **tab, d_struct *data, d_struct *poscoins)
{
  find1(tab, data, poscoins);
  find2(tab, data, poscoins);
  return;
}
