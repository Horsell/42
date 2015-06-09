/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 18:03:36 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/09 19:19:39 by jpirsch          ###   ########.fr       */
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
			e->clist->underlined = "se";
			e->clist->prev->underlined = "us";
			break ;
		}
		if (e->clist->next)
			e->clist = e->clist->next;
		else
			return ;
		first = 0;
	}
	e->clist = tmp;
}

void	down(t_env *e)
{
	int	first;
	t_clist	*tmp;

	first = 1;
	tmp = e->clist;
	while (e->clist)
	{
		if (e->clist->isfirst != first)
			return ;
		if (!ft_strncmp(e->clist->underlined, "us", 2))
		{
			e->clist->underlined = "se";
			e->clist->next->underlined = "us";
			break ;
		}
		if (e->clist->next)
			e->clist = e->clist->next;
		else
			return ;
		first = 0;
	}
	e->clist = tmp;
}

void	right()
{
}
