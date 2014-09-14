/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/13 19:35:02 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/14 04:05:37 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

char	*ft_strdup(char *str)
{
	char *copy;

	copy = malloc(sizeof(char *) * ft_strlen(str));
	copy = str;
	return (copy);
}
