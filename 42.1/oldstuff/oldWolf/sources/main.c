/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/14 23:06:05 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "wolf.h"

int		main(void)
{
	int	fd;
	int	**map;

	if ((fd = open("ressources/map", O_RDONLY)) > 0)
		if ((map = parse(fd)) != NULL)
			if (!(sdl_env(map)))
				return (-1);
	return (0);
}
