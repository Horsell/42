/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/09 20:04:07 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ajdsfh()
{
	ecrire une fonction qui retourne l'elem de la liste selectione
}

void	select_elem(t_env *e)
{
	int		first;
	t_clist	*tmp;

	first = 1;
	tmp = e->clist;
	while (e->clist)
	{
		if (e->clist->isfirst != first)
			return ;
		if (!ft_strncmp(e->clist->underlined, "us", 2))
		{
			if (!ft_strncmp(e->clist->selected, "so", 2))
				e->clist->selected = "se";
			else
				e->clist->selected = "so";
			break ;
		}
		if (e->clist->next)
			e->clist = e->clist->next;
		first = 0;
	}
	e->clist = tmp;
}

void	myread(t_env *e)
{
	char	buf[4];
	int		x;

	x = 0;
	while (buf[0] != 4)			
	{
		display_args(e->clist);
		buf[0] = 0;
		buf[1] = 0;
		buf[2] = 0;
		buf[3] = 0;
		read(0, buf, 4);
		x = (buf[3] << 24) + (buf[2] << 16) + (buf[1] << 8) + buf[0];
		if (x == 27)
			break ;
		(x == 32) ? select_elem(e) : 1;
		(x == 4348699) ? down(e) : 1;
		(x == 4283163) ? up(e) : 1;
     }
}

int		main(int ac, char **av)
{
	t_env	*e;

	signals();
	e = init_select(ac, av);
	myread(e);
	close_select(e);
	return (0);
}
