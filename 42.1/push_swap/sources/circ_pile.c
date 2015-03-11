/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 01:28:45 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/11 05:09:13 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		*create_pile(int ac, char **av)
{
	int	*p;

	if (!(p = malloc(sizeof(int) * ac - 1)))
		return (NULL);
	while (--ac > 0)
		p[ac - 1] = ft_atoi(av[ac]);
	return (p);
}

void	push(int *p, int val, int n)
{
	p[n] = val;
}

void	pop(int *p, int n)
{
	p[n] = 0;
}

void	display_pile(int *p, int ac)
{
	while (--ac > 0)
	{
		ft_putnbr(p[ac - 1]);
		ft_putchar(' ');
	}
}

void	swap_pile(int *p, int ac)
{
	ft_swap(&(p[ac]), &(p[ac - 1]));
}
