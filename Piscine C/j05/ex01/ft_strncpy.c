/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 15:10:52 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/03 17:31:11 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i <= n)
	{
		if (i != n)
			dest[i] = src[i];
		else if (i == n)
			dest[i] = '\n';
		i++;
	}
	return (dest);
}
