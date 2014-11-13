/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 02:02:46 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/12 02:02:49 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (1);
	if ((base % 2) == 0)
		base = base / 2;
	else
		base = (base * 3) + 1;
	return (ft_collatz_conjecture(base));
}
