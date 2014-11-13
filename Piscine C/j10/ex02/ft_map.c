/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 02:55:51 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/09 20:42:37 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int(*f)(int))
{
	int *tab_copy;

	tab_copy = malloc(sizeof(int) * length);
	while (length-- > 0)
		*tab_copy++ = f(*tab++);
	return (tab_copy);
}
