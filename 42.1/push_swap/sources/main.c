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

int		is_option(char *arg)
{
	if (ft_strcmp("-c", arg))// || ft_strcmp("-v", arg))
		return (0);
	ft_putstr("arg:");
	ft_putstr(arg);
	ft_putstr(" ");
	return (1);
}

int		is_valid_int(char *arg)
{
	int	i;

	i = 0;
	if (ft_strlen(arg) == 11 &&  arg[0] == '-')
		if (ft_strcmp("-2147483648", arg) < 0)
			return (0);
	if (ft_strlen(arg) == 10 && ft_isdigit(arg[0]))
		if (ft_strcmp("2147483647", arg) < 0)
			return (0);
	if (ft_strlen(arg) == 11 && arg[0] == '+')
		if (ft_strcmp("2147483647", &arg[1]) < 0)
			return (0);
	if (ft_strlen(arg) > 11 || (ft_strlen(arg) > 10 && ft_isdigit(arg[0])))
		return (0);
	while (arg[i])
	{
		if (i == 0 && !(ft_isdigit(arg[i])) && arg[i] != '-' && arg[i] != '+')
			return (0);
		if (!(ft_isdigit(arg[i])) && i > 0)
			return (0);
		i++;
	}
	return (1);
}

int		check_args(int ac, char **av)
{
	int	nbarg;
	int	i;

	i = 1;
	while (is_option(av[i]))
		i++;
	ft_putnbr(i);
	while (--ac > i)
	{
		ft_putnbr(ac);
		nbarg = ac;
		if (!is_valid_int(av[ac]))
			return (0);
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
