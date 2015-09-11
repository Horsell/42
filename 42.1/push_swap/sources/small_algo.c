/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 15:24:43 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/11 15:46:25 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_small_pile(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (!a)
		return ;
	if (is_sort(*a))
		return ;
	
}

//	ABC -> return
//  ACB -> rra sa
//  BAC -> sa
//  BCA -> rra
//  CBA -> ra sa
//  CAB -> ra
