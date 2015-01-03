/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 07:31:16 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/02 22:09:30 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	int		**map;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		fd = open("maps/42.fdf", O_RDONLY);
	if ((map = parse(fd)))
		env(map);
	return (0);
}
