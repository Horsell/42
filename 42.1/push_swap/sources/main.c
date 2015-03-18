/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 03:28:26 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/18 18:26:51 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		main(int ac, char **av)
{
	int		i;
	t_pile	*a;
	t_pile	*b;

	if (ac == 1)
	{
		ft_putendl("");
		return (0);
	}
	i = 1;
	a = NULL;
	b = NULL;
	while (i < ac)
	{
		a = push(a, ft_atoi(av[i]));
		i++;
	}
	display_pile(a);
	algo(&a, &b, ac - 1);
	ft_putendl("");
	//swap_pile(&a);
	display_pile(a);
	/*b = push_swap(&a, b);
	ft_putendl("");
	display_pile(b);
	swap_two_pile(&a, &b);
	ft_putendl("");
	display_pile(a);
	ft_putendl("");
	display_pile(b);*/
	return (0);
}
