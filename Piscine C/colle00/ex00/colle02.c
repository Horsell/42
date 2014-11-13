/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/30 17:18:07 by kmasson           #+#    #+#             */
/*   Updated: 2014/08/30 17:24:16 by kmasson          ###   ########.fr       */
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
			if (b == 1 && (a == 1 || a == x))
				ft_putchar('A');
			else if (b == y && (a == 1 || a == x))
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
