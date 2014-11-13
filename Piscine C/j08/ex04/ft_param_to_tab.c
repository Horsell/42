/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 20:52:50 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/08 21:29:43 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdlib.h>

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str)
		i++;
	return (i);
}

t_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int i;
	int j;
	t_stock_par	*tab_struct;

	i = 0;
	tab_struct = malloc(sizeof(t_stock_par) * (ac));
	while (i < (ac))
	{
		tab_struct[i].size_param = ac;
		tab_struct[i].str = av[i];
		tab_struct[i].copy = malloc(sizeof(char) * ft_strlen(av[i]));
		j = 0;
		while (j < ft_strlen(av[i])
		{
			tab_struct[i].copy[j] = av[i][j];
			j++;
		}
		tab_struct[i].tab = ft
		i++;
	}
	return (tab);
}

int			main(int ac, char **av)
{
	ft_param_to_tab(ac, av);
	return (0);
}
