/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 15:25:01 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/28 18:40:04 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_list **a, t_list **b, t_env *e)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	push(a, *(int*)(tmp->content));
	pop_back(a);
	if (e->v)
		ft_putstr("rra ");
	if (e->opt_v && e->v)
		display_pile(*a, *b);
}

void	rev_rotate_b(t_list **a, t_list **b, t_env *e)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	push(b, *(int*)(tmp->content));
	pop_back(b);
	if (e->v)
		ft_putstr("rrb ");
	if (e->opt_v && e->v)
		display_pile(*a, *b);
}

void	swap_a(t_list **a, t_list **b, t_env *e)
{
	int	tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *(int*)(*a)->next->content;
	*(int*)(*a)->next->content = *(int*)(*a)->content;
	*(int*)(*a)->content = tmp;
	if (e->v)
		ft_putstr("sa ");
	if (e->opt_v && e->v)
		display_pile(*a, *b);
}

void	swap_b(t_list **a, t_list **b, t_env *e)
{
	int	tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *(int*)(*b)->next->content;
	*(int*)(*b)->next->content = *(int*)(*b)->content;
	*(int*)(*b)->content = tmp;
	if (e->v)
		ft_putstr("sb ");
	if (e->opt_v && e->v)
		display_pile(*a, *b);
}
