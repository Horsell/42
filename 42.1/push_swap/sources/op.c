/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 17:15:03 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/01 00:13:34 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_list **a, t_list **b, t_env *e)
{
	if (!b || !a || !*b)
		return (0);
	if (!*a)
	{
		*a = ft_lstnew((*b)->content, sizeof(int));
		pop(b);
	}
	else
	{
		push(a, *(int*)(*b)->content);
		pop(b);
	}
	if (e->v)
		ft_putstr("pa ");
	if (e->opt_v && e->v)
		display_pile(*a, *b, e);
	return (1);
}

int	push_b(t_list **a, t_list **b, t_env *e)
{
	if (!a || !b || !*a)
		return (0);
	if (!*b)
	{
		*b = ft_lstnew((*a)->content, sizeof(int));
		pop(a);
	}
	else
	{
		push(b, *(int*)(*a)->content);
		pop(a);
	}
	if (e->v)
		ft_putstr("pb ");
	if (e->opt_v && e->v)
		display_pile(*a, *b, e);
	return (1);
}

int	rotate_a(t_list **a, t_list **b, t_env *e)
{
	if (!(*a) || !(*a)->next)
		return (0);
	push_back(a, *(int*)(*a)->content);
	pop(a);
	if (e->v)
		ft_putstr("ra ");
	if (e->opt_v && e->v)
		display_pile(*a, *b, e);
	return (1);
}

int	rotate_b(t_list **a, t_list **b, t_env *e)
{
	if (!(*b) || !(*b)->next)
		return (0);
	push_back(b, *(int*)(*b)->content);
	pop(b);
	if (e->v)
		ft_putstr("rb ");
	if (e->opt_v && e->v)
		display_pile(*a, *b, e);
	return (1);
}
