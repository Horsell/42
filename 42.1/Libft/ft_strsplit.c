/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 07:56:07 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/14 18:06:25 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *s, char c)
{
	int	i;
	int	n;
	
	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c || i == 0) && s[i + 1] != c && s[i + 1] != '\0')
			n++;
		i++;
	}
	return (n);
}

static char		**ft_stabmalloc(size_t nbstr)
{
	char	**stab;

	if (!(stab = (char**)malloc(sizeof(char**) * nbstr)))
		return (NULL);
	ft_bzero(stab, nbstr);
	return (stab);
}

static size_t		ft_strchr_len(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (0);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**strtab;
	size_t	size;
	size_t	n;
	size_t	i;

	if (!s || !c || !*s)
		return (NULL);
	n = ft_countwords(s, c);
	if (!(strtab = ft_tabmalloc(n + 1, ft_strlen((char*)s))))
		return (NULL);
	size = 0;
	i = 0;
	while (i < n)
	{
		if ((size = ft_strchr_len(s, c)) <= 1)
			size = ft_strlen((char*)s);
		strtab[i] = ft_strsub(s, 0, size);
		s = s + size + 1;
		i++;
	}
	return (strtab);
}
