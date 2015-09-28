/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 19:12:16 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/28 19:12:53 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_findmin(t_list *a)
{
	int	min;
	int	i;
	int	j;

	min = *(int*)(a->content);
	i = 0;
	j = 0;
	while (a)
	{
		if (*(int*)(a->content) < min)
		{
			min = *(int*)(a->content);
			j = i;
		}
		if (!(a->next))
			break ;
		a = a->next;
		++i;
	}
	return (j);
}
