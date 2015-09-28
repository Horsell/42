/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 17:15:03 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/28 19:12:55 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_getsize(t_list *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	ft_getmin(t_list **a, t_list **b, t_env *e)
{
	int	n;
	int	i;
	int	size;

	size = ft_getsize(*a);
	n = ft_findmin(*a);
	i = 0;
	if (n < size / 2)
	{
		while (i < n)
		{
			rotate_a(a, b, e);
			++i;
		}
	}
	else
	{
		while (i < size - n)
		{
			rev_rotate_a(a, b, e);
			++i;
		}
	}
}

int		is_sort(t_list *a)
{
	int	n;
	int	i;

	i = 0;
	if (!a)
		return (0);
	n = *(int*)(a->content);
	while (a)
	{
		if (*(int*)(a->content) >= n)
			n = *(int*)(a->content);
		else
			return (0);
		a = a->next;
		i++;
	}
	return (i);
}

void	back_swap(t_list **a, t_list **b, t_env *e)
{
	rev_rotate_a(a, b, e);
	if (is_sort((*a)->next) == ft_getsize(*a) - 1)
	{
		ft_putstr("rra ");
		if (e->opt_v)
			display_pile(*a, *b);
		e->v = 1;
		rev_rotate_a(a, b, e);
		swap_a(a, b, e);
		rotate_a(a, b, e);
		rotate_a(a, b, e);
		return ;
	}
	else
		rotate_a(a, b, e);
}

void	sort_pile(t_list **a, t_list **b, t_env *e)
{
	t_list	*tmp;

	tmp = NULL;
	if (!a)
		return ;
	if (is_sort(*a))
		return ;
	back_swap(a, b, e);
	e->v = 1;
	while ((*a)->next && !(is_sort(*a)))
	{
		if (is_sort((*a)->next))
			swap_a(a, b, e);
		else
		{
			ft_getmin(a, b, e);
			push_b(a, b, e);
		}
	}
	while (*b)
		push_a(a, b, e);
	ft_putendl("");
}
