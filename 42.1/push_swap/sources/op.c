/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 17:15:03 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/28 18:39:39 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **a, t_list **b, t_env *e)
{
	if (!b)
		return ;
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
		display_pile(*a, *b);
}

void	push_b(t_list **a, t_list **b, t_env *e)
{
	if (!a)
		return ;
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
		display_pile(*a, *b);
}

void	rotate_a(t_list **a, t_list **b, t_env *e)
{
	push_back(a, *(int*)(*a)->content);
	pop(a);
	if (e->v)
		ft_putstr("ra ");
	if (e->opt_v && e->v)
		display_pile(*a, *b);
}

void	rotate_b(t_list **a, t_list **b, t_env *e)
{
	push_back(b, *(int*)(*b)->content);
	pop(b);
	if (e->v)
		ft_putstr("rb ");
	if (e->opt_v && e->v)
		display_pile(*a, *b);
}
