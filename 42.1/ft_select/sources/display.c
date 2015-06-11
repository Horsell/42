/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 14:16:28 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/12 00:18:02 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	display_args(t_env *e)
{
	int		first;
	int		i;
	t_clist	*tmp;

	first = 1;
	i = 0;
	initialize_terminal();
	tputs(tgetstr("cl", NULL), 1, ft_putc);
	while (e->clist)
	{
	tmp = e->clist;
		if (e->clist->isfirst != first)
			break ;
		tputs(tgetstr(e->clist->underlined, NULL), 1, ft_putc);
		tputs(tgetstr(e->clist->selected, NULL), 1, ft_putc);
		if (e->nbargs > e->win->ws_row)
		{
			ft_putstr(e->clist->arg);
			i = 0;
			while (i < e->win->ws_row)
			{
				tmp = tmp->next;
				i++;
			}
			ft_putchar('\t');
			ft_putnbr(i);
			ft_putstr(tmp->arg);
			ft_putchar('\n');
		}
		else
			ft_putendl(e->clist->arg);
		if (e->clist->next)
			e->clist = e->clist->next;
		else
			break ;
		first = 0;
	}
	tputs(tgetstr("se", NULL), 1, ft_putc);
	tputs(tgetstr("ue", NULL), 1, ft_putc);
}
