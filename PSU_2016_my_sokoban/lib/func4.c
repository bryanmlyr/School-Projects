/*
** func4.c for func4 in /home/r00t/Desktop/PSU/PSU_2016_my_sokoban/lib
**
** Made by r00t
** Login   <r00t@epitech.net>
**
** Started on  Fri Dec 16 14:22:51 2016 r00t
** Last update Mon Dec 19 18:50:55 2016 r00t
*/

 #include "../inc/my.h"

void	callthem(char **s)
{
  initscr();
  noecho();
  cbreak();
  signal(SIGWINCH, NULL);
  keypad(stdscr, TRUE);
  curs_set(FALSE);
  printwtab(s);
}

void	checkcc(char **s)
{
  if (check_coins(s) == 0)
    {
      clear();
      refresh();
      printw("GG ! You won !\nPress a key to quit...");
      getch();
      endwin();
      exit(0);
    }
}

int	restart(int key, char **s
		, d_struct *data, d_struct *poscoins)
{
  if (key == 32)
    {
      clear();
      refresh();
      find_player1(s, data);
      findcoinsarr(s, data, poscoins);
      return (1);
    }
  return (0);
}

int	check_if_lose(char **s)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (s[x])
    {
      y = 0;
      while (s[x][y] != '\n')
	{
	  if ((s[x][y] == 'X' && s[x - 1][y] == '#' && s[x][y + 1] == '#')
	      || (s[x][y] == 'X' && s[x + 1][y] == '#' && s[x][y - 1] == '#')
	      || (s[x][y] == 'X' && s[x + 1][y] == '#' && s[x][y + 1] == '#')
	      || (s[x][y] == 'X' && s[x - 1][y] == '#' && s[x][y - 1] == '#'))
	    return (-1);
	  y++;
	}
      x++;
    }
  return (0);
}

void	premain(int ac, char **av)
{
  d_struct	*data;
  d_struct	*poscoins;
  char		**s;
  int		key;

  data = malloc(sizeof(d_struct));
  poscoins = malloc(sizeof(d_struct));
  s = tabmap(map(ac, av));
  data->ac = ac;
  data->av = av;
  callthem(s);
  while (key != 'q')
    {
      key = getch();
      (restart(key, s, data, poscoins) == 1) ? premain(ac, av) : 0;
      s = keys1(s, data, poscoins, key);
      s = keys2(s, data, poscoins, key);
      if (checkpos(tabmap(map(ac, av)), s) == 0)
	{
	  endwin();
	  exit(0);
	}
    }
  endwin();
  exit(0);
}
