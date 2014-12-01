/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 20:53:08 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/21 07:29:10 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "get_next_line.h"

char	*line_join(char *buf, char **tmp)
{
	size_t	len;
	char	*line;

	len = ft_strchr_len(buf, '\n');
	line = malloc(sizeof(char*) * len + 1);
	if (len)
		line = ft_strsub(buf, 0, len);
	buf += (len + 1);
	ft_putendl("malloc and len worked");
	ft_putendl(buf);
	//*tmp = ft_strdup(buf);
		ft_putstr("taille tmp : ");
		ft_putnbr(ft_strchr_len(buf, '\0'));
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUF_SIZE + 1];
	int				ret;
	static char		**info = NULL;
	char			idfd;

	if (fd < 0 || fd > 255)
		return (-1);
	if (!info)
	{
		if (info = ft_memalloc(sizeof(char *) * 256) == NULL)
			return (-1);
	}
	if (info[idfd])
	{
		tmp = ft_strchr(info[idfd], '\n');
	}
	return (0);
}


/*
	if ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
	}
	else if
	{
	}
	else*/