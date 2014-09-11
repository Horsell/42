/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/04 12:16:23 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/04 12:30:39 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(void)
{
	int a;
	int b;
	char s[8] = "a et b :";

	a = 4;
	b = 7;
	ft_swap(&a, &b);
	ft_putstr(s);
	ft_putchar(a + '0');
	ft_putchar(b + '0');
	ft_putchar('\n');
	ft_putchar(ft_strlen(s) + '0');
	ft_putchar(ft_strcmp("a et c", s));
	return (0);
}
