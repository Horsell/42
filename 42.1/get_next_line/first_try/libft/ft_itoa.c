/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 10:46:38 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/12 02:55:23 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	str = ft_strnew(11);
	size = 0;
	while ((n / 10) > 9)
		size++;
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
		ft_itoa(-n);
	/*else if (n > 9)
	else
	*/	
}
