/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 20:04:46 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/02 01:43:58 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin2(const char *s1, const char *s2, int ret)
{
	size_t	size;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (s1 ? ft_strdup((char*)s1) : ft_strdup((char*)s2));
	size = (ft_strlen((char*)s1) + ret);
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	while (*s1)
	{
		*str = *(char*)s1;
		s1++;
		str++;
	}
	free((char*)s1 - (size - ret));
	while (*s2)
	{
		*str = *(char*)s2;
		s2++;
		str++;
	}
	*str = '\0';
	return (str - size);
}

int		get_next_line(int fd, char **line)
{
	static size_t	index = 0;
	static char		*tmp = NULL;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (index == 0)
	{
		while ((ret = read(fd, buff, BUFF_SIZE)))
		{
			buff[ret] = '\0';
			tmp = ft_strjoin2(tmp, buff, ret);
		}
		if (ret <= 0 && !tmp)
			return (-1);
	}
	if (tmp[index] == '\0')
		return (0);
	if ((*line = ft_strsub(tmp, index, ft_strchr_len(&tmp[index], '\n'))))
		index += ft_strchr_len(&tmp[index], '\n');
	else if (tmp[index] == '\n')
		*line = ft_strdup("");
	index++;
	return (1);
}
