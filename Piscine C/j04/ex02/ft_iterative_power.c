/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 12:36:54 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/02 12:46:01 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_power(int nb, int power)
{
	int i;
	int result;

	result = nb;
	i = 1;
	while (i < power)
	{
		result = result * nb;
		i++;
	}
	return (result);
}
