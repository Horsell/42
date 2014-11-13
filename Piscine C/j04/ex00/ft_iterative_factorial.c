/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 22:28:54 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/02 20:28:00 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int result;

	
	result = 1;
	i = 1;
	while (i <= nb)
	{
		result = i * result;
		i++;
	}
	return (result);
}
