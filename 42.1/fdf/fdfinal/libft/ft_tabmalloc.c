/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 15:43:44 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/02 21:32:22 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_tabmalloc(size_t size, size_t len)
{
	void	*tab;
	size_t	i;

	i = 0;
	if (!(tab = malloc(size * len)))
		return (NULL);
	ft_bzero(tab, len);
	return (tab);
}
