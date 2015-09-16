/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 15:25:01 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/16 05:15:52 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	push(a, *(int*)(tmp->content));
	pop_back(a);
	ft_putstr("rra ");
}

void	rev_rotate_b(t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	push(b, *(int*)(tmp->content));
	pop_back(b);
	ft_putstr("rrb ");
}

void	swap_a(t_list **a)
{
	int	tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *(int*)(*a)->next->content;
	*(int*)(*a)->next->content = *(int*)(*a)->content;
	*(int*)(*a)->content = tmp;
	ft_putstr("sa ");
}

void	swap_b(t_list **b)
{
	int	tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *(int*)(*b)->next->content;
	*(int*)(*b)->next->content = *(int*)(*b)->content;
	*(int*)(*b)->content = tmp;
	ft_putstr("sb ");
}
