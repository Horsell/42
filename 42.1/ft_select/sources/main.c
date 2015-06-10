/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/10 13:23:01 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_clist	*is_underlined(t_clist *clist)
{
	int		first;
	t_clist	*tmp;

	first = 1;
	tmp = clist;
	while (clist)
	{
		if (clist->isfirst != first)
			return (NULL);
		if (!ft_strncmp(clist->underlined, "us", 2))
			return (clist);
		if (clist->next)
			clist = clist->next;
		first = 0;
	}
	clist = tmp;
	return (NULL);
}

void	select_elem(t_env *e)
{
	t_clist	*tmp;

	tmp = is_underlined(e->clist);
	if (!tmp)
		return ;
	if (!ft_strncmp(tmp->selected, "so", 2))
		tmp->selected = "se";
	else
		tmp->selected = "so";
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
