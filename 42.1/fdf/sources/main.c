/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 07:31:16 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/14 05:32:10 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	int		**map;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		fd = open("maps/42.fdf", O_RDONLY);
	if (fd > 0)
		if ((map = parse(fd)))
			env(map);
	return (0);
}
