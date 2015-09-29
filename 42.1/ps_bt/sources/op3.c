/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 19:25:30 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/29 19:24:22 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **a, t_list **b, t_env *e)
{
	if (!a || !b)
		return ;
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	swap_a(a, b, e);
	swap_b(a, b, e);
}

void	rr(t_list **a, t_list **b, t_env *e)
{
	if (!a || !b)
		return ;
	if (!*a || !*b)
		return ;
	rotate_a(a, b, e);
	rotate_b(a, b, e);
}

void	rrr(t_list **a, t_list **b, t_env *e)
{
	if (!a || !b)
		return ;
	if (!*a || !*b)
		return ;
	rev_rotate_a(a, b, e);
	rev_rotate_b(a, b, e);
}
