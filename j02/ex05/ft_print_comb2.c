/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/29 14:26:36 by jpirsch           #+#    #+#             */
/*   Updated: 2014/08/29 15:05:46 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_print(char a, char b)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb2(void)
{
	char a;
	char b;
	char c;
	char d;

	a = '0';
	b = '0';
	while (a <= '9' && b <= '9')
	{

}

int		main(void)
{
	ft_print_comb2();
	return (0);
}
