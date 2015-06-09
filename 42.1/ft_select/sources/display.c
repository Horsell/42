/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 14:16:28 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/09 19:15:09 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	display_args(t_clist *clist)
{
	int	first;

	first = 1;
	tputs(tgetstr("cl", NULL), 1, ft_putc);
	while (clist)
	{
		if (clist->isfirst != first)
			return ;
		tputs(tgetstr(clist->underlined, NULL), 1, ft_putc);
		tputs(tgetstr(clist->selected, NULL), 1, ft_putc);
		ft_putendl(clist->arg);
		if (clist->next)
			clist = clist->next;
		else
			return ;
		first = 0;
	}
	tputs(tgetstr("se", NULL), 1, ft_putc);
	tputs(tgetstr("ue", NULL), 1, ft_putc);
}
