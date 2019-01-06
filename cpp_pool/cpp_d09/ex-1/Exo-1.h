/*
** EPITECH PROJECT, 2018
** ex-1
** File description:
** ex-1
*/

#ifndef EXO_H_
	#define EXO_H_

typedef	struct	s_cthulhu
{
	int	m_power;
	char	*m_name;
}		cthulhu_t;

typedef struct	s_koala
{
	cthulhu_t	m_parent;
	char		m_isALegend;
}		koala_t;

static void	CthulhuInitializer(cthulhu_t *);
cthulhu_t	*NewCthulhu();
void		PrintPower(cthulhu_t *);
void		Attack(cthulhu_t *);
void		Sleeping(cthulhu_t *);
static void	KoalaInitializer(koala_t *, char *, char);
koala_t		*NewKoala(char *, char);
void		Eat(koala_t *);

#endif /* !EXO-1_H_ */
