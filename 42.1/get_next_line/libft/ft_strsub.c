/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:26:19 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/15 14:26:48 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (len == 0)
		return (ft_strdup(""));
	if (!(str = ft_strnew(len)))
		return (NULL);
	s += start;
	while (len--)
	{
		str[i] = s[i];
		if (str[i] == '\0')
			return (str);
		i++;
	}
	str[i] = '\0';
	return (str);
}
