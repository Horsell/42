/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 16:34:02 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/09 19:59:17 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "operators.h"
#include "do_op.h"
#include <stdlib.h>

int		ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		nu;

	i = 0;
	sign = 1;
	nu = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (ft_is_digit(str[i]) == 0)
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] != '\0' && ft_is_digit(str[i]) == 1)
		nu = nu * 10 + (str[i++] - '0');
	return (sign * nu);
}

int		ft_check_av(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
			i++;
	while (str[i] != '\0')
	{
		if (str[i] <= 57 && str[i] >= 48)
			i++;
		else
			return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	int tab[1];
	int (*tab_op[4])(int, int);

	tab_op[0] = &ft_add;
	tab_op[1] = &ft_substract;
	tab_op[2] = &ft_divide;
	tab_op[3] = &ft_multiply;
	tab_op[4] = &ft_modulo;
	if (ac == 4 && ft_check_av(av[1]) && ft_check_av(av[3]) == 1)
	{
		tab[0] = ft_atoi(av[1]);
		tab[1] = ft_atoi(av[3]);
	}
	ft_putnbr(tab[0]);
	ft_putchar(' ');
	ft_putstr(av[2]);
	ft_putchar(' ');
	ft_putnbr(tab[1]);
	ft_putstr(" = ");
	if (av[2][0] == '+')
		ft_putnbr(tab_op[0](tab[0], tab[1]));
	if (av[2][0] == '-')
		ft_putnbr(tab_op[1](tab[0], tab[1]));
	if (av[2][0] == '/')
		ft_putnbr(tab_op[2](tab[0], tab[1]));
	if (av[2][0] == '*')
		ft_putnbr(tab_op[3](tab[0], tab[1]));
	if (av[2][0] == '%')
		ft_putnbr(tab_op[4](tab[0], tab[1]));
	return (0);
}
