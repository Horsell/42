/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 17:15:03 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/14 20:50:25 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push(t_list **pile, int val)
{
	if (!pile)
		return ;
	if (!(*pile))
		*pile = ft_lstnew(&val, sizeof(int));
	else
		ft_lstadd(pile, ft_lstnew(&val, sizeof(int)));
}

void	display_pile(t_list *a, t_list *b)
{
	ft_putendl("Pile a :");
	while (a)
	{
		ft_putnbr(*(int*)(a->content));
		ft_putchar(' ');
		if (!(a->next))
			break ;
		a = a->next;
	}
	ft_putendl("");
	ft_putendl("Pile b :");
	while (b)
	{
		ft_putnbr(*(int*)(b->content));
		ft_putchar(' ');
		if (!(b->next))
			break ;
		b = b->next;
	}
}

int		ft_min(t_list *a)
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

void	push_b(t_list *a, t_list **b)
{
	if (!a)
		return ;
	if (!*b)
		*b = ft_lstnew(a->content, sizeof(int));
}

void	pop(t_list **pile)
{
	if (!(*pile))
		return ;
		
}

void	pop_back(t_list **pile)
{
}

void	rotate(t_list **pile)
{
	
}

t_list	*ft_getmin(t_list *a)
{
	int n;
	int	i;

	n = ft_min(a);
	i = 0;
	while (i < n && a)
	{
		rotate(a);
		++i;
	}
	return (a);
}

void	sort_pile(t_list *a, t_list *b)
{
	t_list	*tmp;

	tmp = NULL;
	if (!a)
		return ;
	push_b(a, &b);
	display_pile(a, b);
/*	while (a->next)
	{
		a = ft_getmin(a);
		
		a = a->next;
	}*/
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac != 1)
	{
		while (--ac)
			push(&a, ft_atoi(av[ac]));
		display_pile(a, b);
		sort_pile(a, b);
		//display_pile(a, b);
	}
	ft_putendl("");
	return (0);
}
