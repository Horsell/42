/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 17:15:03 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/14 20:50:25 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	if (!b)
		return ;
	if (!*a)
	{
		*a = ft_lstnew((*b)->content, sizeof(int));
		pop(b);
	}
	else
	{
		push(a, *(int*)(*b)->content);
		pop(b);
	}
//	ft_putstr("pa");
}

void	push_b(t_list **a, t_list **b)
{
	if (!a)
		return ;
	if (!*b)
	{
		*b = ft_lstnew((*a)->content, sizeof(int));
		pop(a);
	}
	else
	{
		push(b, *(int*)(*a)->content);
		pop(a);
	}
//	ft_putstr("pb");
}

void	rotate(t_list **pile)
{
	push_back(pile, *(int*)(*pile)->content);
	pop(pile);
//	ft_putstr("r");
}

void	rev_rotate(t_list **pile)
{
	t_list	*tmp;

	tmp = *pile;
	while (tmp->next)
		tmp = tmp->next;
	push(pile, *(int*)(tmp->content));
	pop_back(pile);
//	ft_putstr("rr");
}
