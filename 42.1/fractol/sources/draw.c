/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:38:59 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/16 04:15:05 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
//#include <complex.h>
#include "mlx.h"
#include "fractol.h"
#include "libft.h"

void	cas0(t_env *e, int v, int p, int t)
{
	e->r = v;
	e->g = t;
	e->b = p;
}

void	cas1(t_env *e, int v, int p, int q)
{
	e->r = q;
	e->g = v;
	e->b = p;
}

void	cas2(t_env *e, int v, int p, int t)
{
	e->r = p;
	e->g = v;
	e->b = t;
}

void	cas3(t_env *e, int v, int p, int q)
{
	e->r = p;
	e->g = q;
	e->b = v;
}

void	cas4(t_env *e, int v, int p, int t)
{
	e->r = t;
	e->g = p;
	e->b = v;
}

void	hsv_to_rgb(t_env *e, double h, double s, double v)
{
	double	hh;
	double	p;
	double	q;
	double	t;
	double	ff;
	int	i;

	hh = h / 60;
	i = floor(hh);
	ff = hh - i;
	p = v * (1.0 - s);
	q = v * (1.0 - (s * ff));
	t = v * (s * (1.0 - ff));
	p *= 250;
	q *= 250;
	t *= 250;
	(i == 0) ? cas0(e, v, p, t) : 1;
	(i == 1) ? cas1(e, v, p, q) : 1;
	(i == 2) ? cas2(e, v, p, t) : 1;
	(i == 3) ? cas3(e, v, p, q) : 1;
	(i == 4) ? cas4(e, v, p, t) : 1;
	if (i == 5)
	{
        e->r = v;
        e->g = p;
        e->b = q;
	}
}

void	color(t_env *e, int i, int x1, int y1)
{
	double	h;
	double	s;
	double	v;

	if (i == e->max_iter)
	{
		e->r = 0;
		e->g = 0;
		e->b = 0;
		px_to_img(e, (int)x1, (int)y1);
	}
	else
	{
		h = i * (360 / e->max_iter);
		s = e->h + 1 - (double)i / e->max_iter;
		v = e->v + 1 - (double)i / e->max_iter;
//		s = e->h + (double)i / e->max_iter;
//		v = e->v + (double)i / e->max_iter;
		hsv_to_rgb(e, h, s, v);
		px_to_img(e, (int)x1, (int)y1);
	}
}

void	mandelbrot(t_env *e, int x1, int y1)
{
	int		i;
	t_pt	zn;
	t_pt	c;
	t_pt	temp;

	i = 0;
	zn.x = (((double)x1 / 1440) * 3 - e->decalx) * e->zoom;
	zn.y = (((double)y1 / 900) * 2 - e->decaly) * e->zoom;
	c.x = e->x;
	c.y = e->y;
	while (i < e->max_iter && c.x * c.x + c.y * c.y < 4)
	{
		temp.x = c.x * c.x - c.y * c.y + zn.x;
		temp.y = 2 * c.x * c.y + zn.y;
		if (c.x == temp.y && c.y == temp.y)
			i = e->max_iter;
		c.y = temp.y;
		c.x = temp.x;
		++i;
	}
	color(e, i, x1, y1);
/*	if (i != 0)
		e->r = 225 - 2 * (250 / i);
	if (x1 >= 0 && x1 < 1440 && y1 >= 0 && y1 < 900)
		px_to_img(e, (int)x1, (int)y1);*/
}

void	julia(t_env *e, int x1, int y1)
{
	int		i;
	t_pt	zn;
	t_pt	c;
	t_pt	temp;

	i = 0;
//	zn.x = (((double)x1 / 1440) * e->zoom)- e->decalx;
//	zn.y = (((double)y1 / 900) * e->zoom) - e->decaly;
	zn.x = ((((double)x1 / 1440) - ((double)x1 / (1440 * 2))) * e->zoom) - e->decalx;
	zn.y = ((((double)y1 / 1440) - ((double)y1 / (1440 * 2))) * e->zoom) - e->decaly;
	c.x = e->x;
	c.y = e->y;
	while (i < e->max_iter && zn.x * zn.x + zn.y * zn.y < 4)
	{
		temp.x = zn.x * zn.x - zn.y * zn.y + c.x;
		temp.y = 2 * zn.x * zn.y + c.y;
		if (zn.x == temp.x && zn.y == temp.y)
			i = e->max_iter;
		zn.y = temp.y;
		zn.x = temp.x;
		++i;
	}
	color(e, i, x1, y1);
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
