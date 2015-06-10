/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 15:50:23 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/10 13:14:17 by jpirsch          ###   ########.fr       */
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

void	ft_clstdel(t_clist *alst)
{
//	t_clist	*tmp;

	if (!(alst))
		return ;
	free(alst);
/*	while (alst)
	{
		if (alst->next)
		{
			tmp = alst;
			alst = alst->next;
			free(tmp);
		}
		else
			free(alst);
	}*/
}
