/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 17:02:45 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/12 17:02:48 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_compact(char **tab, int length)
{
	int		i;
	int		y;

	i = 0;
	while (tab[i])
	{
		y = 0;
		while (tab[i][y])
		{
			if (tab[i][y] == '0')
				length = length - 1;
			y++;
		}
		i++;
	}
	return (length);
}
