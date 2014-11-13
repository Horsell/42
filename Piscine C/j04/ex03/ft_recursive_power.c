/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 12:46:41 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/02 13:34:14 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_recursive_power(int nb, int power)
{
	if (nb <= 0 || power <= 0)
	{
		return (0);
	}
	else if (power > 1 && nb > 0)
	{
		int result;
		
		result = nb * ft_recursive_power(nb, power - 1);
		return (result);
	}
	else if (power == 1 && nb != 0)
		return (nb);
	else
		return (1);
}
