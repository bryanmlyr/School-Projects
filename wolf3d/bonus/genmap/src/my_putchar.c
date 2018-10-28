/*
** my_putchar.c for my_putchar.c in /home/Siloki/Piscine #1 2016/newlib
** 
** Made by Bryan Maloyer
** Login   <Siloki@epitech.net>
** 
** Started on  Thu Oct 20 22:13:13 2016 Bryan Maloyer
** Last update Thu Oct 20 22:13:55 2016 Bryan Maloyer
*/

#include <unistd.h>

void	my_putchar(char str)
{
  write(1, &str, 1);
}
