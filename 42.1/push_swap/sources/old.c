/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 01:28:45 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/16 05:32:16 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_pile	*create_pile(int ac, char **av)
{
	t_pile *p;

	if (!(p = malloc(sizeof(t_pile))))
		return (NULL);
	if (!(p->tab = malloc(sizeof(int) * ac - 1)))
		return (NULL);
	p->n = ac - 1;
	while (--ac > 0)
		p->tab[ac - 1] = ft_atoi(av[ac]);
	return (p);
}

void	push(t_pile *p, int val)
{
	++p->n;
	p->tab[p->n - 1] = val;
}

void	pop(t_pile *p)
{
	if (p->n > 0)
	{
		p->tab[p->n - 1] = 0;
		--p->n;
	}
}

void	display_pile(t_pile *p)
{
	int i;

	i = p->n;
	while (--i >= 0)
	{
		ft_putnbr(p->tab[i]);
		ft_putchar(' ');
	}
}

void	swap_pile(t_pile *p)
{
	ft_swap(&(p->tab[p->n - 1]), &(p->tab[p->n - 2]));
}
