/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/11 23:40:02 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/11 23:40:04 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"
#define BUF_SIZE	4096

int		main(int ac, char **av)
{
	char	str[BUF_SIZE];
	int		fd;
	int		i;
	int		ret;

	i = 1;
	while (ac >= 2)
	{
		fd = open(av[i], O_RDONLY);
		while ((ret = read(fd, str, BUF_SIZE)))
			write(1, str, ret);
		fclose(fd);
		ac--;
		i++;
	}
	return (0);
}
