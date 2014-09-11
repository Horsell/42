/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 20:07:49 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/07 21:29:09 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_display(char **tab)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(tab[i][j]);
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char	**ft_tabcpy(char **av)
{
	char **tab;
	int compt;
	int i;
	int j;

	compt = 0;
	tab = av;
	i = 0;
	while (i < 9)
	{
		tab[i] = av[i +1];
		j = 0;
		while (j < 9)
		{
			tab[i][j] = av[i + 1][j];
			if (av[i + 1][j] == '.')
			{
				tab[i][j] = '0';
				compt++;
			}
			j++;
		}
		i++;
	}
	if (compt < 17)
		ft_putstr("Erreur\n");
	return (tab);
}
