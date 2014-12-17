/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 07:31:16 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/17 02:15:33 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "get_next_line.h"
#include "fdf.h"
#include "parsemap.h"
#include <fcntl.h>

int		**ft_realloc(int **map, int len)
{
	int	**remap;
	int	i;

	i = 1;
	if (map)
	{
		remap = malloc(sizeof(int**) * (len + 1));
		while (map[i])
		{
			remap[i] = map[i];
			i++;
		}
	}
	else
		remap = malloc(sizeof(int**) * 1);
	remap[0] = &len;
	return (remap);
}

int		main(void)
{
	int		fd;
	size_t	i;
	int		j;
	char	*line;
	int		**map;

	fd = open("map", O_RDONLY);
	i = 1;
	while ((get_next_line(fd, &line)) > 0)
	{
		map = ft_realloc(map, (ft_strlen(line) + 1));
	ft_putnbr(map[0][0]);
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
