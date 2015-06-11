/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 18:03:36 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/11 23:28:01 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	left(t_env *e)
{
	t_clist	*clist;
	int		i;

	i = 0;
	clist = is_underlined(e->clist);
	if (!clist)
		return ;
	clist->underlined = "ue";
	while (i < e->win->ws_row)
	{
		clist = clist->prev;
		i++;
	}
	clist->underlined = "us";
}

void	up(t_env *e)
{
	t_clist	*clist;

	clist = is_underlined(e->clist);
	if (!clist)
		return ;
	clist->underlined = "ue";
	clist->prev->underlined = "us";
}

void	down(t_env *e)
{
	t_clist	*clist;

	clist = is_underlined(e->clist);
	if (!clist)
		return ;
	clist->underlined = "ue";
	clist->next->underlined = "us";
}

void	right(t_env *e)
{
	t_clist	*clist;
	int		i;

	i = 0;
	clist = is_underlined(e->clist);
	if (!clist)
		return ;
	clist->underlined = "ue";
	while (i < e->win->ws_row)
	{
		clist = clist->next;
		i++;
	}
	clist->underlined = "us";
}
