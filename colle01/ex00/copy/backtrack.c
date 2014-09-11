/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 16:44:10 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/07 23:17:48 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"backtrack.h"
#include	"ft.h"
#include	<stdlib.h>
int		ft_is_full(char **tab);

int		backtrack(char **tab, int position)
{
	int i;
	int j;
	char n;

	i = (position / 9) + '0';
	j = (position % 9) + '0';
	n = '1';
	if (position == 81)
		return (1);
	if (tab[i][j] != '0')
		return backtrack(tab, position+1);
	while (n <= '9')
	{
		if (test_value(tab, i, j, n) == 1)
		{
			tab[i][j] = n;
			ft_putchar('8');
			if (backtrack(tab, position + 1))
				return (1);
		}
	}
	tab[i][j] = '0';
	return (0);
}

int		test_value(char **tab, int i, int j, char n)
{
	if (exist_in_row(tab, n, i) == 0)
	{
		if (exist_in_column(tab, n, j) == 0)
		{
			if (exist_in_square(tab, n, i, j) == 0)
				tab[i][j] = n;
			else
				return (0);
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int 	exist_in_row(char **tab, char n, int i)
{
	int j;

	j = 0;
	while (j < 8)
	{
		if (tab[i][j] == n)
			return (1);

	}
	return (0);
}

int 	exist_in_column(char **tab, char n, int j)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (tab[i][j] == n)
			return (1);
		i++;
	}
	return (0);
}

int 	exist_in_square(char **tab, char n, int i, int j)
{
	int i2;
	int j2;

	i2 = i - i % 3;
	j2 = j - j % 3;
	while (i < i2 + 3)
	{
		j = j2;
		while (j < j + 3)
		{
			if (tab[i][j] == n)
				return (1);
			j++;
		}
	}
	return (0);
}
