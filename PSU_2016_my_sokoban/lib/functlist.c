/*
** functlist.c for listechainée in /home/r00t/Desktop/elementary_programming/CPE_2016_Pushswap/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Sat Nov 19 18:01:43 2016 r00t
** Last update Sun Dec 18 10:51:48 2016 r00t
*/

#include "../inc/my.h"

void		pushtop(d_liste **p, int x, int y)
{
  d_liste	*element;
  element = malloc(sizeof(d_liste));
  if (element == NULL)
    return;
  element->x[0] = x;
  element->x[1] = y;
  element->next = *p;
  *p = element;
}

int	longpile(d_liste *p)
{
  int	x;

  x = 0;
  while (p)
    {
      p = p->next;
      x++;
    }
  return (x);
}
