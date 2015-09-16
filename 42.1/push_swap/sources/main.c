/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 17:15:03 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/16 06:40:47 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putendl("");
}

int		check_args(int ac, char **av)
{
	int	nbarg;
	int	i;

	while (--ac)
	{
		nbarg = ac;
		i = 0;
		while (av[ac][i])
		{
			if (!(ft_isdigit(av[ac][i])) && i > 0)
				return (0);
			if (i > 9) // test int value in the 2*10^9 range
				return (0);
			i++;
		}
		while (--nbarg)
		{
			if (ft_atoi(av[ac]) == ft_atoi(av[nbarg]))
				return (0);
		}
	}
	return (1);
}

int		make_pile(int ac, char **av, t_list **a)
{
	if (!(check_args(ac, av)))
		return (0);
	while (--ac)
		push(a, ft_atoi(av[ac]));
	return (1);
}

int		main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac != 1)
	{
		if (!(make_pile(ac, av, &a)))
		{
			ft_putendl("Error");
			return (0);
		}
		display_pile(a, b);
		if (ft_getsize(a) == 3)
			sort_pileof3(&a, &b);
		else
			sort_pile(&a, &b);
		display_pile(a, b);
	}
	else
		ft_putendl("");
	return (0);
}
