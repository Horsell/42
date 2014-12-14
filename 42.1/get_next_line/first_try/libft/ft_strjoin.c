/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 00:49:57 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/01 23:48:32 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (s1 ? ft_strdup((char*)s1) : ft_strdup((char*)s2));
	size = (ft_strlen((char*)s1) + ft_strlen((char*)s2));
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	ft_putnbr(size);
	while (*s1)
	{
		*str = *(char*)s1;
		s1++;
		str++;
	}
	while (*s2)
	{
		*str = *(char*)s2;
		s2++;
		str++;
	}
	*str = '\0';
	ft_putstr(str - 10);
	ft_putchar('\n');
	return (str - size);
}
