/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 19:25:30 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/30 01:07:06 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ss(t_list **a, t_list **b, t_env *e)
{
	if (!a || !b)
		return (0);
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return (0);
	swap_a(a, b, e);
	swap_b(a, b, e);
	return (1);
}

int	rr(t_list **a, t_list **b, t_env *e)
{
	if (!a || !b)
		return (0);
	if (!*a || !*b)
		return (0);
	rotate_a(a, b, e);
	rotate_b(a, b, e);
	return (1);
}

int	rrr(t_list **a, t_list **b, t_env *e)
{
	if (!a || !b)
		return (0);
	if (!*a || !*b)
		return (0);
	rev_rotate_a(a, b, e);
	rev_rotate_b(a, b, e);
	return (1);
}
