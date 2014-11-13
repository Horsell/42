/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/30 06:42:44 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/01 12:07:07 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

int	main(void)
{
	int un = 1;
	int *********i;
	int ********j;
	int *******k;
	int ******l;
	int *****m;
	int ****n;
	int ***o;
	int **p;
	int *q;
	int a = 14, b = 3, div = 0, mod = 0;
	char str[5] = "haha";

	q	=	&un;
	p	=	&q;
	o	=	&p;
	n	=	&o;
	m	=	&n;
	l	=	&m;
	k 	=	&l;
	j 	=	&k;
	i	=	&j;
	ft_ft(q);
	ft_ultimate_ft(i);
	ft_putchar(un);
	ft_putchar('\n');
	ft_div_mod(a, b, &div, &mod);
	ft_putchar(div + 60);
	ft_putchar(mod + 60);
	ft_putchar('\n');
	a = 14;
	b = 3;
	ft_ultimate_div_mod(&a, &b);
	ft_putchar(a + 60);
	ft_putchar(b + 60);
	ft_putchar('\n');
	ft_putstr(str);
	ft_putchar('\n');
	ft_putchar(ft_strlen(str) + 60);
	ft_putchar('\n');
	ft_swap(&a, &b);
	ft_putchar(a + 60);
	ft_putchar(b + 60);
	ft_putchar('\n');
	ft_putstr(ft_strrev(str));
	ft_putchar('\n');
	ft_putchar(ft_atoi("123"));
	return (0);
}
