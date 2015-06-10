/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 18:03:36 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/10 15:35:29 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	left(t_env *e)
{
	if (e->clist)
		e->clist = e->clist->prev;
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

void	right()
{
}
