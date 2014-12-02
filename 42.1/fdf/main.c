/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 07:31:16 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/02 07:51:59 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"
#include "parsemap.h"
#include <fcntl.h>

int		main(void)
{
	int		fd;
	size_t	i;
	int		j;
	char	*line;
	int		**map;

	fd = open("map", O_RDONLY);
	i = 0;
	map = (int**)malloc(sizeof(int**) * 20);
	while ((get_next_line(fd, &line)) > 0)
	{
		map[i] = parse_map(line);
		j = 1;
		while (j < map[i][0])
		{
			ft_putnbr(map[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	//ft_putnbr(i);
	fdf(map);
	return (0);
}
