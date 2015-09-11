/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 15:25:01 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/11 15:25:03 by jpirsch          ###   ########.fr       */
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
	ft_putstr("rra");
}

void	rev_rotate_b(t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	push(b, *(int*)(tmp->content));
	pop_back(b);
	ft_putstr("rrb");
}
