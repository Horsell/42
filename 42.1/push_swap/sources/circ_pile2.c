/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_pile2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 01:31:17 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/11 03:36:33 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap_two_pile(int *a, int *b, int ac)
{
	swap_pile(a, ac);
	swap_pile(b, ac);
}

void	push_swap(int *a, int *b, int n)
{
	push(b, a[n], n);
	pop(b, n);
}
