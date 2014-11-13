/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 17:44:12 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/03 18:44:20 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	int cmp;

	cmp = 0;
	i = 0;
	while (i <= n)
	{
		cmp += s2[i] - s1[i];
		i++;
	}
	return (i);
}

int		main(void)
{
	char s1[8] = "aaahihoh";
	char s2[7] = "aaawgvg";
	int i;

	i = ft_strncmp(s1, s2, 7);
	//i = strncmp(s1, s2, 7);
	printf("%d", i);
	return (0);
}
