/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 18:51:05 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/30 23:04:41 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_option(char *arg, t_env *e)
{
	if (!(ft_strcmp("-c", arg)))
	{
		e->opt_c = 1;
		return (1);
	}
	else if (!(ft_strcmp("-v", arg)))
	{
		e->opt_v = 1;
		return (1);
	}
	return (0);
}

int		is_valid_int(char *arg)
{
	int	i;

	i = 0;
	if (ft_strlen(arg) == 11 && arg[0] == '-')
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

int		check_args(int ac, char **av, t_env *e)
{
	int	nbarg;
	int	i;

	i = 1;
	while (i < ac && is_option(av[i], e))
		i++;
	while (--ac >= i)
	{
		nbarg = ac;
		if (!is_valid_int(av[ac]))
			return (0);
		while (--nbarg >= i)
		{
			if (ft_atoi(av[ac]) == ft_atoi(av[nbarg]))
				return (0);
		}
	}
	ac++;
	return (ac);
}
