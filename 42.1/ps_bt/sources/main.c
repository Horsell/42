/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 17:15:03 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/29 19:49:03 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_pile(t_list *a, t_list *b, t_env *e)
{
	(e->opt_c) ? ft_putendl("\033[37m\nPile a :\033[33m") : \
		ft_putendl("\nPile a :");
	while (a)
	{
		ft_putnbr(*(int*)(a->content));
		ft_putchar(' ');
		if (!(a->next))
			break ;
		a = a->next;
	}
	(e->opt_c) ? ft_putendl("\033[37m\nPile b :\033[33m") : \
		ft_putendl("\nPile b :");
	while (b)
	{
		ft_putnbr(*(int*)(b->content));
		ft_putchar(' ');
		if (!(b->next))
			break ;
		b = b->next;
	}
	(e->opt_c) ? ft_putendl("\033[31m") : ft_putendl("");
}

int		make_pile(int ac, char **av, t_list **a, t_env *e)
{
	int i;

	i = 1;
	if (!(i = check_args(ac, av, e)))
		return (0);
	while (--ac >= i)
		push(a, ft_atoi(av[ac]));
	return (1);
}

t_env	*init_env(void)
{
	t_env	*e;

	e = malloc(sizeof(t_env));
	if (e)
	{
		e->opt_c = 0;
		e->opt_v = 0;
		e->v = 0;
	}
	return (e);
}

int		main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_env	*e;

	e = init_env();
	if (ac != 1)
	{
		if (!(make_pile(ac, av, &a, e)))
		{
			ft_putendl("Error");
			return (0);
		}
		if (e->opt_c)
			ft_putstr("\033[31m");
		if (ft_getsize(a) == 3)
			sort_pileof3(&a, &b, e);
		else if (ft_getsize(a) <= 7)
			backtrack(&a, &b, e, 0);
		else
			sort_pile(&a, &b, e);
		if (e->opt_c)
			ft_putstr("\033[0m");
		ft_putendl("");
	}
	else
		ft_putendl("");
	return (0);
}
