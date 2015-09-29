/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushnpop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 17:15:03 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/16 06:41:07 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **pile, int val)
{
	if (!pile)
		return ;
	if (!(*pile))
		*pile = ft_lstnew(&val, sizeof(int));
	else
		ft_lstadd(pile, ft_lstnew(&val, sizeof(int)));
}

void	push_back(t_list **pile, int val)
{
	if (!pile)
		return ;
	if (!(*pile))
		*pile = ft_lstnew(&val, sizeof(int));
	else
		ft_lstaddend(pile, ft_lstnew(&val, sizeof(int)));
}

void	ft_mydel(void *content, size_t content_size)
{
	ft_bzero(content, content_size);
	free(content);
}

void	pop_back(t_list **pile)
{
	t_list	*tmp;
	t_list	*todel;

	if (!(*pile))
		return ;
	tmp = *pile;
	while (tmp->next)
	{
		if (!(tmp->next->next))
			break ;
		tmp = tmp->next;
	}
	todel = tmp->next;
	tmp->next = NULL;
	ft_lstdelend(&todel, ft_mydel);
}

void	pop(t_list **pile)
{
	if (!(*pile))
		return ;
	ft_lstdelone(pile, ft_mydel);
}
