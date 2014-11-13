/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/13 19:35:02 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/11 10:53:28 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*copy;
	int		i;

	copy = malloc(sizeof(char *) * ft_strlen(str));
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}
