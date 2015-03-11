/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:38:59 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/11 21:18:31 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <math.h>
#include "mlx.h"
#include "fractol.h"
#include "libft.h"

void	mandelbrot(t_env *e, int x1, int y1)
{
	int		i;
	t_pt	z;
	double	x;
	double	y;
	double	xtemp;

	i = 0;
	z.x = (((double)x1 / 1440) * 3 - e->decalx) * e->zoom;
	z.y = (((double)y1 / 900) * 2 - e->decaly) * e->zoom;
	x = e->x;
	y = e->y;
	while (i < 100 && x * x + y * y < 4)
	{
		xtemp = x * x - y * y + z.x;
		y = 2 * x * y + z.y;
		x = xtemp;
		++i;
	}
	if (i != 0)
		e->r = 225 - 2 * (250 / i);
	if (x1 >= 0 && x1 < 1440 && y1 >= 0 && y1 < 900)
		px_to_img(e, (int)x1, (int)y1);
}

void	julia(t_env *e, int x1, int y1)
{
	int		i;
	t_pt	z;
	double	x;
	double	y;
	double	xtemp;

	i = 0;
	x = (((double)x1 / 1440) * 3 - e->decalx) * e->zoom;
	y = (((double)y1 / 900) * 2 - e->decaly) * e->zoom;
	z.x = e->x;
	z.y = e->y;
	while (i < 100 && x * x + y * y < 4)
	{
		xtemp = x * x - y * y + z.x;
		y = 2 * x * y + z.y;
		x = xtemp;
		++i;
	}
	if (i != 0)
		e->r = 225 - 2 * (250 / i);
	if (x1 >= 0 && x1 < 1440 && y1 >= 0 && y1 < 900)
		px_to_img(e, (int)x1, (int)y1);
}

void	loop(t_env *e, int n)
{
	int		i;
	int		j;

	i = (n == 1) ? 0 : 450;
	while (i < 900 / n)
	{
		j = 0;
		while (j < 1440)
		{
			if (e->fract_type == 1)
				mandelbrot(e, j, i);
			else
				julia(e, j, i);
			++j;
		}
		++i;
	}
}

void	draw(t_env *e)
{
	t_pt	start;

	test();
	ft_bzero(e->data, e->size_line * 900);
	if (e->fract_type == 2)
	{
		start.x = 720;
		start.y = 450;
		draw_tree(e, start, -(M_PI / 2), 9);
		draw_tree(e, start, (M_PI / 2), 9);
	}
	else
	{
		loop(e, 1);
		loop(e, 2);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
