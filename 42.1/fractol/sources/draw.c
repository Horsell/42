/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:38:59 by jpirsch           #+#    #+#             */
/*   Updated: 2015/02/10 10:58:39 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fdf.h"
#include "libft.h"

void	calc(t_env *e, int x1, int y1)
{
	int		i;
	double	x0;
	double	y0;
	double	x;
	double	y;
	double	xtemp;

	i = 0;
	x0 = (((double)x1 / 1440) * 3 - e->decalx) * e->zoom;
	y0 = (((double)y1 / 900) * 2 - e->decaly) * e->zoom;
	x = e->x;
	y = e->y;
	while (i < 1000 && x * x + y * y < 4)
	{
		xtemp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtemp;
		i++;
	}
	e->R = 4 * (250 / i);
	e->G = 2 * (250 / i);
	if (x1 >= 0 && x1 < 1440 && y1 >= 0 && y1 < 900)
		px_to_img(e, (int)x1, (int)y1);
}

void	calc2(void)
{
/*	t_pt	X, Y, X0, Y0, D, A0, B0, C0;
	double	xtemp;
	double	x2temp;

	X0.x = X0.y = 0.0
	A0 = 1.0;
	X = Y = b0 = c0 = dnx = dny = 0.0;*/
	// X(i + 1) = X(i) * X(i) + X0;
}

void	draw(t_env *e)
{
	int		i;
	int		j;

	ft_bzero(e->data, e->size_line * 900);
	if (e->fract_type == 1)
	{
		i = 0;
		while (i < 900)
		{
			j = 0;
			while (j < 1440)
			{
				calc(e, j, i);
				j++;
			}
			i++;
		}
	}
	else
	{
		calc2();
	}

	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	print_state(e);
}
