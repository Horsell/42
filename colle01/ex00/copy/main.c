/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 16:42:03 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/07 23:14:34 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "backtrack.h"

int		main(int ac, char **av)
{
	char **tab;

	if (ac == 10)
	{
		tab = ft_tabcpy(av);
		ft_display(tab);
		ft_putchar('\n');
		backtrack(tab, 0);
		ft_display(tab);
	}
	else
		ft_putstr("Erreur\n");
	return (0);
}
