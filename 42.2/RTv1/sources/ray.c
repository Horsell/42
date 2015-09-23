/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sven <jpirsch@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 03:33:46 by sven              #+#    #+#             */
/*   Updated: 2015/05/11 20:33:49 by sven             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rtv1.h"

void	set_ray(t_env *e, int i, int j)
{
	RD[i * POS_HEIGHT + j].x = (j / POS_WIDTH) * 1.7;
	RD[i * POS_HEIGHT + j].y = (i / POS_HEIGHT) * 1.7;
	RD[i * POS_HEIGHT + j].z = 1;
	RD[i * POS_HEIGHT + j].r = 0;
	RD[i * POS_HEIGHT + j].g = 0;
	RD[i * POS_HEIGHT + j].b = 0;
}
