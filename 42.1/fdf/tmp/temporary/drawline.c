/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 07:45:37 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/16 09:19:53 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "drawline.h"
#include "libft.h"

void	putline(void *mlx_ptr, void *win_ptr, t_coord start, t_coord end)
{
	double	dd;
	double	x;
	double	y;
	double	dx;
	double	dy;

	x = start.x;
	y = start.y;
	dx = end.x - start.x;
	dy = end.y - start.y;
	dd = sqrt((dx * dx) + (dy * dy));
	dx = dx/dd;
	dy = dy/dd;
	while (dd-- >= 0)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
		x += dx;
		y += dy;
	}
}
