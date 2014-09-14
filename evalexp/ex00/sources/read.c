/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 21:07:08 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/14 21:30:21 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_operators.h"

void			*ft_binary(char c)
{
	if (c == '*')
		return (&ft_multiply);
	if (c == '/')
		return (&ft_divide);
	if (c == '%')
		return (&ft_modulo);
	if (c == '+')
		return (&ft_add);
	if (c == '-')
		return (&ft_substract);
	else
	{
		ft_putstr("Parse error");
		return (0);
	}
}

int			ft_expect(char c)
{
	if (c == '*' || c == '/' || c == '%' || c == '+' || c == '-')
		return (1);
	else if ( c == '(' || c == ')' || ft_atoi(&c))
		return (1);
	else
	{
		ft_putstr("Parse error");
		return (0);
	}
}
