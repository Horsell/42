/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 17:15:03 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/11 15:22:29 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findmin(t_list *a)
{
	int	min;
	int	i;
	int	j;

	min = *(int*)(a->content);
	i = 0;
	j = 0;
	while (a)
	{
		if (*(int*)(a->content) < min)
		{
			min = *(int*)(a->content);
			j = i;
		}
		if (!(a->next))
			break ;
		a = a->next;
		++i;
	}
	return (j);
}

int	ft_getsize(t_list *a)
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

void	ft_getmin(t_list **a)
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
			rotate_a(a);
			++i;
		}
	}
	else
	{
		while (i < size - n)
		{
			rev_rotate_a(a);
			++i;
		}
	}
}

int		is_sort(t_list *a)
{
	int	n;

	if (!a)
		return (0);
	n = *(int*)(a->content);
	while (a)
	{
		if (*(int*)(a->content) >= n)
		{
			n = *(int*)(a->content);
		}
		else
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_pile(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (!a)
		return ;
	if (is_sort(*a))
		return ;
	while ((*a)->next)
	{
		ft_getmin(a);
		push_b(a, b);
	}
	while (*b)
	{
		push_a(a, b);
	}
}
