/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 20:53:08 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/20 09:11:29 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "get_next_line.h"

char	**split_buf(char **line, char *buf, size_t *imax)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strchr_len(buf, '\n');
	line = malloc(sizeof(char **) * 10);
	while (len)
	{
		line[i] = malloc(sizeof(char*) * len + 1);
		ft_bzero(line[i], len + 1);
		line[i] = ft_strsub(buf, 0, len);
		buf += len + 1;
		len = ft_strchr_len(buf, '\n');
		i++;
	}
		ft_putnbr(i);
	*imax = i;
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUF_SIZE + 1];
	int				ret;
	static t_gnl	inf;

	if (inf.index == 0)
	{
		ft_bzero(buf, BUF_SIZE + 1);
		ret = read(fd, buf, BUF_SIZE);
		if (ret == 0)
			return (0);
		else if (ret == -1)
			return (-1);
		inf.tab = split_buf(inf.tab, buf, &inf.imax);
		inf.index++;
		return (1);
	}
	else
	{
		if (inf.index == inf.imax)
			return (0);
		else
		{
			ft_putendl(inf.tab[inf.index]);
			inf.index++;
			return (1);
		}
	}
}
