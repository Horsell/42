/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 07:42:00 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/17 02:18:14 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsemap.h"

int		*parse_map(char *line, int n)
{
	size_t	n;
	int		*map;
	char	**str;
	size_t	j;

	map = (int*)malloc(sizeof(int*) * n);
	str = ft_strsplit(line, ' ');
	map[0] = n;
	j = 1;
	while (j < n)
	{
		map[j] = ft_atoi(str[j - 1]);
		j++;
	}
	return (map);
}
