/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 03:28:26 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/11 05:08:08 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		main(int ac, char **av)
{
	int *a;
	int *b;

	a = create_pile(ac, av);
	b = create_pile(ac, av);
	b = ft_memset(b, 0, ac);

	display_pile(a, ac);
	ft_putendl("");
	display_pile(b, ac);
//	pop(&pa);
//	pa = pa->next;
//	display_pile(pa);
	return (0);
}
