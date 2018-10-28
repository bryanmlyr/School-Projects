/*
** my_putstr.c for my_putstr.c in /home/Siloki/CPool_Day04/tests
** 
** Made by Bryan Maloyer
** Login   <Siloki@epitech.net>
** 
** Started on  Thu Oct  6 11:44:44 2016 Bryan Maloyer
** Last update Mon Oct 17 11:02:01 2016 Bryan Maloyer
*/

void	my_putchar(char c);

int	my_putstr(char *str)
{
  int	x;

  x = 0;
  while (str[x] != '\0')
    {
      my_putchar(str[x]);
      x++;
    }
}
