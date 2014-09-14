/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 13:14:54 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/09 21:14:00 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(char *tab, int(*f)(int, int))
{
	int i;
	int order;

	i = 0;
	order = f(tab[0], tab[1]);
	while (tab[i + 1])
	{
		if (f(tab[i], tab[i + 1]) != order && f(tab[i], tab[i + 1]) != 0)
			return (0);
		i++;
	}
	return (1);
}
