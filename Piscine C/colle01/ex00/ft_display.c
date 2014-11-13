/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 14:08:12 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/07 19:51:48 by mvercout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_display(char **tab)
{
	int x;
	int y;

    y = 0;
    while (y <= 8)
    {
        x = 0;
        while (x <= 8)
        {
            ft_putchar(tab[x][y]);
            (x != 8) ? ft_putchar(' ') : 0 ;
            x++;
        }
        ft_putchar('\n');
        y++;
    }
}
