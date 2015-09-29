/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 03:20:08 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/23 17:37:43 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int n;

	n = ft_strlen((char*)s);
	s += n;
	while (n + 1)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		n--;
	}
	return (NULL);
}
