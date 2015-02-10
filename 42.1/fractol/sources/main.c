/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 07:31:16 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/09 02:49:52 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fdf.h"

int		main(int ac, char **av)
{
	int		fract_type;

	if (ac == 2)
		fract_type = av[1][0];
	else
		fract_type = 1;
	env(fract_type);
	return (0);
}
