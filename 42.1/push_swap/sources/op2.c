/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 15:25:01 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/30 01:06:39 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rotate_a(t_list **a, t_list **b, t_env *e)
{
	t_list	*tmp;

	if (!(*a) || !(*a)->next)
		return (0);
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	push(a, *(int*)(tmp->content));
	pop_back(a);
	if (e->v)
		ft_putstr("rra ");
	if (e->opt_v && e->v)
		display_pile(*a, *b, e);
	return (1);
}

int	rev_rotate_b(t_list **a, t_list **b, t_env *e)
{
	t_list	*tmp;

	if (!(*b) || !(*b)->next)
		return (0);
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	push(b, *(int*)(tmp->content));
	pop_back(b);
	if (e->v)
		ft_putstr("rrb ");
	if (e->opt_v && e->v)
		display_pile(*a, *b, e);
	return (1);
}

int	swap_a(t_list **a, t_list **b, t_env *e)
{
	int	tmp;

	if (!(*a) || !(*a)->next)
		return (0);
	tmp = *(int*)(*a)->next->content;
	*(int*)(*a)->next->content = *(int*)(*a)->content;
	*(int*)(*a)->content = tmp;
	if (e->v)
		ft_putstr("sa ");
	if (e->opt_v && e->v)
		display_pile(*a, *b, e);
	return (1);
}

int	swap_b(t_list **a, t_list **b, t_env *e)
{
	int	tmp;

	if (!(*b) || !(*b)->next)
		return (0);
	tmp = *(int*)(*b)->next->content;
	*(int*)(*b)->next->content = *(int*)(*b)->content;
	*(int*)(*b)->content = tmp;
	if (e->v)
		ft_putstr("sb ");
	if (e->opt_v && e->v)
		display_pile(*a, *b, e);
	return (1);
}
