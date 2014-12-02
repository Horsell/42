/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 07:45:37 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/02 07:49:03 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	putline(void *mlx_ptr, void *win_ptr, t_coord start, t_coord end)
{
	int	dx;
	int	dy;
	int	D;
	int	x;
	int	y;

	dx = end.x - start.x;
	dy = end.y - start.y;
	D = 2 * dy - dx;
	if (dx > dy)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, start.x, start.y, 0xFF0000);
		x = start.x + 1;
		y = start.y;
		while (x <= end.x)
		{
			if (D > 0)
			{
				y++;
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
				D = D + (2 * dy - 2 * dx);
			}
			else
			{
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
				D = D + (2 * dy);
			}
			x++;
		}
	}
	else
	{
		mlx_pixel_put(mlx_ptr, win_ptr, start.x, start.y, 0xFF0000);
		x = start.x;
		y = start.y + 1;
		while (y <= end.y)
		{
			if (D > 0)
			{
				x++;
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
				D = D + (2 * dx - 2 * dy);
			}
			else
			{
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
				D = D + (2 * dx);
			}
			y++;
		}
	}
}
