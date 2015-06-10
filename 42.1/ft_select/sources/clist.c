/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 15:50:23 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/10 16:24:56 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_clist	*ft_clstnew(char *arg, int isfirst)
{
	t_clist *new;

	if (!(new = malloc(sizeof(t_clist))))
		return (NULL);
	if (!arg)
		new->arg = NULL;
	else
		new->arg = arg;
	new->isfirst = isfirst;
	new->selected = "se";
	if (new->isfirst)
		new->underlined = "us";
	else
		new->underlined = "ue";
	new->next = new;
	new->prev = new;
	return (new);
}

void	ft_clstadd(t_clist **last, t_clist **first, t_clist *new)
{
	if (!(last) || !(first))
		return ;
	if (!(*last) || !(*first) || !(new))
		return ;
	(*last)->next = new;
	new->prev = (*last);
	new->next = (*first);
	(*first)->prev = new;
	(*last) = new;
}

void	ft_clstdelone(t_clist **alst)
{
	if (!alst)
		return ;
	free(*alst);
	*alst = NULL;
}

void	ft_clstdel(t_clist **alst)
{
	if (!(alst))
		return ;
	if ((*alst)->next->isfirst != 1)
		ft_clstdel(&((*alst)->next));
	ft_clstdelone(alst);
}
