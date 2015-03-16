/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_pile2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 01:31:17 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/16 04:44:04 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap_two_pile(t_pile *a, t_pile *b)
{
	swap_pile(a);
	swap_pile(b);
}

void	push_swap(t_pile *a, t_pile *b)
{
	push(b, a->tab[a->n]);
	pop(b);
}
