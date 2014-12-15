/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 07:45:37 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/15 20:19:20 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "drawline.h"
#include "libft.h"

/*void	putline(void *mlx_ptr, void *win_ptr, t_coord start, t_coord end)
{
	int	dx;
	int	dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	if (dx > dy && dx >= 0 && dy >= 0)
		aaaa(mlx_ptr, win_ptr, start, end, dx, dy);
	else if (dx < dy && dx >= 0 && dy >= 0)
		bbbb(mlx_ptr, win_ptr, start, end, dx, dy);
	//else if (dx < dy && dx <= 0 && dy <= 0)
	//	cccc(mlx_ptr, win_ptr, start, end, dx, dy);
}*/

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

void	aaaa(void *mlx_ptr, void *win_ptr, t_coord start, t_coord end, int dx,\
		int dy)
{
	int	D;
	int	x;
	int	y;

	D = 2 * dy - dx;
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

void	bbbb(void *mlx_ptr, void *win_ptr, t_coord start, t_coord end, int dx,\
		int dy)
{
	int	D;
	int	x;
	int	y;

	D = 2 * dy - dx;
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

void	cccc(void *mlx_ptr, void *win_ptr, t_coord start, t_coord end, int dx,\
		int dy)
{
	int	D;
	int	x;
	int	y;

	D = 2 * dy - dx;
	mlx_pixel_put(mlx_ptr, win_ptr, start.x, start.y, 0xFF0000);
	x = start.x;
	y = start.y - 1;
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
		y--;
	}
}
