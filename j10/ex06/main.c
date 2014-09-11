/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 16:34:02 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/10 08:07:45 by jpirsch          ###   ########.fr       */
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
	int	i;
	int sign;
	int n;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] == ' ')
			i++;
	if (ft_is_digit(str[i] == 0))
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while ((str[i + 1] != '\0' || (i + 1) != seg.i) && ft_is_digit(str[i]) == 1)
		n = n * 10 + (str[i++] - '0');
	return (sign * n);
}

int		ft_str_calc()
{
	int		(*tab_op[4])(int, int);
	int		*str_calc;

	str_calc = (int *)malloc(sizeof(int) * (i - y));	
	tab_op[0] = &ft_add;
	tab_op[1] = &ft_substract;
	tab_op[2] = &ft_divide;
	tab_op[3] = &ft_multiply;
	tab_op[4] = &ft_modulo;

	ft_atoi(str_calc);
	return (0);
}
