/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:18:29 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/10 09:57:08 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s1 || !s2 || !size)
		return ;
	while (s1[j])
		j++;
	while (s2[i] /*&& s1[i]*/ && i < size - 1 - j)
	{
		s1[j + i] = s2[i];
		i++;
	}
	s1[j + i] = 0;
	return (j + ft_strlen((char *)s2));
}
