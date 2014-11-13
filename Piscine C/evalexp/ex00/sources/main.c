/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 05:27:47 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/14 11:24:33 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_parse.h"
#include "ft_structures.h"
#include <stdlib.h>

int			main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(btree_infix_traversal(exp_parser(av[1])));
		ft_putchar('\n');
	}
	return (0);
}
