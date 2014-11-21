/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 00:27:21 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/21 04:54:56 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	char	**line;
	size_t	i;
	int		fd;

	i = 0;
	fd = open("ldap", O_RDONLY);
	get_next_line(fd, line);
	//while (get_next_line(fd, line))
	//	ft_putendl(*line);
	return (0);
}
