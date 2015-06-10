/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 14:16:28 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/10 16:54:05 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	display_args(t_env *e)
{
	int	first;

	first = 1;
	initialize_terminal();
	tputs(tgetstr("cl", NULL), 1, ft_putc);
	while (e->clist)
	{
		if (e->clist->isfirst != first)
			break ;
		tputs(tgetstr(e->clist->underlined, NULL), 1, ft_putc);
		tputs(tgetstr(e->clist->selected, NULL), 1, ft_putc);
		ft_putendl(e->clist->arg);
		if (e->clist->next)
			e->clist = e->clist->next;
		else
			break ;
		first = 0;
	}
	tputs(tgetstr("se", NULL), 1, ft_putc);
	tputs(tgetstr("ue", NULL), 1, ft_putc);
	ft_putnbr(e->win->ws_row);
	ft_putnbr(e->nbargs);
}
