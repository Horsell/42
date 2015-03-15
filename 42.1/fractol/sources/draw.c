/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:38:59 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/14 19:37:30 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <complex.h>
#include "mlx.h"
#include "fractol.h"
#include "libft.h"

void	mandelbrot(t_env *e, int x1, int y1)
{
	int		i;
	t_pt	zn;
	t_pt	c;
	double	xtemp;
	double	ytemp;

	i = 0;
	zn.x = (((double)x1 / 1440) * 3 - e->decalx) * e->zoom;
	zn.y = (((double)y1 / 900) * 2 - e->decaly) * e->zoom;
	c.x = e->x;
	c.y = e->y;
	while (i < 100 && c.x * c.x + c.y * c.y < 4)
	{
		xtemp = c.x * c.x - c.y * c.y + zn.x;
		ytemp = 2 * c.x * c.y + zn.y;
		if (c.x == xtemp && c.y == ytemp)
			i = 100;
		c.y = ytemp;
		c.x = xtemp;
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
	t_pt	zn;
	t_pt	c;
	double	xtemp;
	double	ytemp;

	i = 0;
	zn.x = (((double)x1 / 1440) * 3 - e->decalx) * e->zoom ;
	zn.y = (((double)y1 / 900) * 2 - e->decaly) * e->zoom ;
	c.x = e->x;
	c.y = e->y;
	while (i < 100 && zn.x * zn.x + zn.y * zn.y < 4)
	{
		xtemp = zn.x * zn.x - zn.y * zn.y + c.x;
		ytemp = 2 * zn.x * zn.y + c.y;
		if (zn.x == xtemp && zn.y == ytemp)
			i = 100;
		zn.y = ytemp;
		zn.x = xtemp;
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

	ft_bzero(e->data, e->size_line * 900);
	if (e->fract_type == 2)
	{
		start.x = 970 - 100 * e->decalx;
		start.y = 540 - 100 * e->decaly;
		draw_tree(e, start, -(M_PI / 2), 9);
		draw_tree(e, start, (M_PI / 2), 9);
	}
	else
	{
		loop(e, 1);
		loop(e, 2);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_do_sync(e->mlx);
}
