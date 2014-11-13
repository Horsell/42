/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 05:27:47 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/10 12:06:29 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_do_op(char **str);

void	check_segment(char **str)
{

}

void	check_parenthesis(char **str)
{
	t_coord		*seg;

	while (*str[seg.i])
	{
		if (*str[seg.i] == '(')
			seg.y = seg.i;
		if (*str[seg.i] == ')')
			break;
		i++;
	}
	check_segment(&str)
}

int		eval_expr(char *str)
{
	check_parenthesis(&str);
				
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
