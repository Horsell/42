/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/11 23:35:37 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/11 23:37:55 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"
#define BUF_SIZE	4096

int		main(int ac, char **av)
{
	char	str[BUF_SIZE];
	int		fd;
	int		ret;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	while ((ret = read(fd, str, BUF_SIZE)))
		write(1, str, ret);
	close(fd);
	return (0);
}
