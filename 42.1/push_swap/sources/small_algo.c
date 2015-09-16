/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 15:24:43 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/16 06:41:28 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_pileof3(t_list **a, t_list **b)
{
	if (!a)
		return ;
	if (is_sort(*a))
		return ;
	if (*(int*)(*a)->content > *(int*)(*a)->next->content)
	{
		if (*(int*)(*a)->content < *(int*)(*a)->next->next->content)
			swap_a(a);
		else
		{
			rev_rotate_a(a);
			if (*(int*)(*a)->content > *(int*)(*a)->next->content)
				swap_a(a);
		}
	}
	else
	{
		if (*(int*)(*a)->content < *(int*)(*a)->next->next->content)
		{
			rev_rotate_a(a);
			swap_a(a);
		}
		else
			rev_rotate_a(a);
	}
}
