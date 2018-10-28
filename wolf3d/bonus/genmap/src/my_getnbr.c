/*
** my_getnbr.c for my_getnbr.c in /home/Siloki/CPool_Day04/tests
** 
** Made by Bryan Maloyer
** Login   <Siloki@epitech.net>
** 
** Started on  Thu Oct  6 18:12:49 2016 Bryan Maloyer
** Last update Mon Oct 17 21:14:40 2016 Bryan Maloyer
*/
void	my_putchar(char c);

int	my_getnbr(char *str)
{
  int	x;
  int	nb;
  int	neg;

  x = 0;
  nb = 0;
  neg = 1;
  while (str[x])
    {
      if (str[x] == '-' && str[x + 1] >= 48 && str[x + 1] <= 57)
	{
	  neg = -1;
	  x++;
	}
      nb = ((nb * 10) + (str[x] - 48));
      x++;
    }
  return (nb * neg);
}
