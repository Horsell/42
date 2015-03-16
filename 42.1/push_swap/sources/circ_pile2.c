/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_pile2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 01:31:17 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/16 06:51:33 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap_two_pile(t_pile **a, t_pile **b)
{
	swap_pile(a);
	swap_pile(b);
}

t_pile	*push_swap(t_pile **a, t_pile *b)
{
	b = push(b, (*a)->val);
	pop(a);
	return (b);
}
