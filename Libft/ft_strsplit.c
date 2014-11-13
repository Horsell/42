/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 07:56:07 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/13 09:27:15 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	char	**strtab;

	if (!s || !c || !*s)
		return (NULL);
	while (*s)
	{
		if (s == ft_strchr(s, c))
			return ;
		ft_putchar(*s);
	}
	return (strtab);
}
