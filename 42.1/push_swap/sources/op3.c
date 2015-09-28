/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 19:25:30 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/28 19:27:11 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **a, t_list **b, t_env *e)
{
	swap_a(a, b, e);
	swap_b(a, b, e);
}

void	rr(t_list **a, t_list **b, t_env *e)
{
	rotate_a(a, b, e);
	rotate_b(a, b, e);
}

void	rrr(t_list **a, t_list **b, t_env *e)
{
	rev_rotate_a(a, b, e);
	rev_rotate_b(a, b, e);
}
