/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 12:25:53 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/10 05:42:16 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen((char*)s2) - 1;
	if (!*s2)
		return ((char*)s1);
	while (*s1)
	{
		while (*s1 == *s2 && i < n)
		{
			if (i == j)
				return ((char*)s1 - j);
			i++;
			s1++;
			s2++;
		}
		s1++;
	}
	return (NULL);
}
