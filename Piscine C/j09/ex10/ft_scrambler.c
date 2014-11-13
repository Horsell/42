/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrambler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 16:57:59 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/12 16:58:04 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int		tmp_a;
	int		tmp_b;
	int		tmp_c;
	int		tmp_d;

	tmp_a = ***a;
	tmp_b = *b;
	tmp_c = *******c;
	tmp_d = ****d;
	*******c = tmp_a;
	****d = tmp_c;
	*b = tmp_d;
	***a = tmp_b;
}
