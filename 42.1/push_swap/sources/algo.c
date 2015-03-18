/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:05:37 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/18 18:48:34 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_pile **a, t_pile **b, int n)
{
	int i = 0;
	int tp = 0;
	int bempty = 0;

	while (tp != n || bempty)
	{
			push_swap(a, *b);
		if (*a && (*a)->next && (*a)->val > (*a)->next->val)
		{
			swap_pile(a);
		}
		ft_putchar('t');
		while (*b && (*b)->val < (*a)->val)
		{
			push_swap(b, *a);
		}
		ft_putchar('d');
		tp = top_check(*a));
		i++;
	}
}
