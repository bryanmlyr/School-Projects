/*
** my_strcat.c for my_strcat.c in /home/Siloki/CPool_Day07
** 
** Made by Bryan Maloyer
** Login   <Siloki@epitech.net>
** 
** Started on  Tue Oct 11 13:33:22 2016 Bryan Maloyer
** Last update Thu Oct 13 22:09:15 2016 Bryan Maloyer
*/

int	strlenght(char *src)
{
  int	x;

  x = 0;
  while (src[x] != '\0')
    {
      x++;
    }
  return (x);
}

char	*my_strcat(char *dest, char *src)
{
  int	x;
  int	y;

  x = 0;
  y = strlenght(dest);
  while (src[x] != '\0')
    {
      dest[x + y] = src[x];
      x++;
    }
  dest[x + y] = '\0';
  return (dest);
}
