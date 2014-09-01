/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/30 15:24:01 by kmasson           #+#    #+#             */
/*   Updated: 2014/08/30 15:24:02 by kmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	colle(int x, int y)
{
	int	a;
	int	b;

	a = 1;
	b = 1;
	while (b <= y)
	{
		while (a <= x)
		{
			if ((a == 1 || a == x) && (b == y || b == 1))
				ft_putchar('o');
			else if ((a == x || a == 1) && b != 1 && b != y)
				ft_putchar('|');
			else if (b != 1 && b != y && a != 1 && a != x)
				ft_putchar(' ');
			else
				ft_putchar('-');
			a++;
		}
		ft_putchar('\n');
		a = 1;
		b++;
	}
}
