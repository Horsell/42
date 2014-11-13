/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/30 17:27:47 by kmasson           #+#    #+#             */
/*   Updated: 2014/08/30 17:53:17 by kmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	colle(int x, int y)
{
	int	a;
	int	b;

	a = 2;
	b = 1;
	if (x != 0 && y != 0)
		ft_putchar('A');
	while (b <= y && y != 0 && x != 0)
	{
		while (a <= x)
		{
			if (x > 1 && a == x && b == y && y > 1)
				ft_putchar('A');
			else if ((a == x && b == 1) || (b == y && a == 1))
				ft_putchar('C');
			else if (b != 1 && b != y && a != 1 && a != x)
				ft_putchar(' ');
			else
				ft_putchar('B');
			a++;
		}
		ft_putchar('\n');
		a = 1;
		b++;
	}
}
