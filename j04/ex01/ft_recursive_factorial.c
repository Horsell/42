/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 22:58:07 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/02 14:50:13 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb > 12 || nb < 0)
		return (0);
	else if (nb > 1)
	{
		int result;

		result = nb * ft_recursive_factorial(nb - 1);
		return (result);
	}
	else
		return (nb);
}
