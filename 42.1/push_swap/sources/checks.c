/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:18:22 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/18 18:27:45 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		top_check(t_pile *a)
{
	int n;

	if (!a)
		return (0);
	n = 1;
	while (a->next && a->val < a->next->val)
	{
		a = a->next;
		n++;	
	}
	return (n);
}

int		bottom_check(t_pile *a)
{
	int n;

	n = 0;
	while (a->next)
		a = a->next;
	
	return (n);
}
