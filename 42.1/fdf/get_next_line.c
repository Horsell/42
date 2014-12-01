/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 20:04:46 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/26 06:31:44 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_realloc(char *tmp, size_t size)
{
	char	*str;
	int		i;

	i = 0;
	if (!tmp)
	{
		str = malloc(sizeof(char*) * (size + 2));
		ft_bzero(str, (size + 2));
		return (str);
	}
	else
		str = malloc(sizeof(char*)*((ft_strlen(tmp)) + 1 + size));
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
		if (!tmp[i])
			str[i] = tmp[i];
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static size_t	index = 0;
	static char		*tmp = NULL;
	char			buff[BUFF_SIZE + 1];

	ft_bzero(buff, BUFF_SIZE + 1);
	if (index != 0)
	{
		while (tmp[index] == '\n')
			index++;
		if ((*line = ft_strsub(tmp, index, ft_strchr_len(&tmp[index], '\n'))))
		{
			index += ft_strchr_len(&tmp[index], '\n');
			return (1);
		}
		return (0);
	}
	while ((read(fd, buff, BUFF_SIZE)))
	{
		tmp = ft_str_realloc(tmp, (BUFF_SIZE + 1));
		tmp = ft_strjoin(tmp, buff);
	}
	*line = ft_strsub(tmp, 0, ft_strchr_len(tmp, '\n'));
	index += ft_strchr_len(tmp, '\n') + 1;
	return (1);
}
