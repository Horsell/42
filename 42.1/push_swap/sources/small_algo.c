/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 15:24:43 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/28 19:19:59 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	one(t_list **a, t_list **b, t_env *e)
{
	if (*(int*)(*a)->content < *(int*)(*a)->next->next->content)
		swap_a(a, b, e);
	else
	{
		rotate_a(a, b, e);
		if (*(int*)(*a)->content > *(int*)(*a)->next->content)
			swap_a(a, b, e);
	}
}

void	sort_pileof3(t_list **a, t_list **b, t_env *e)
{
	if (!a)
		return ;
	if (is_sort(*a))
		return ;
	e->v = 1;
	if (*(int*)(*a)->content > *(int*)(*a)->next->content)
		one(a, b, e);
	else
	{
		if (*(int*)(*a)->content < *(int*)(*a)->next->next->content)
		{
			rev_rotate_a(a, b, e);
			swap_a(a, b, e);
		}
		else
			rev_rotate_a(a, b, e);
	}
}
