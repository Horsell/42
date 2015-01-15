/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:13:47 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/15 12:21:59 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "wolf.h"

void	draw_line(t_env *e, t_point start, t_point end)
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
	dx = dx / dd;
	dy = dy / dd;
	while (dd-- >= 0)
	{
		if (x < 1440 && x > 0 && y > 0 && y < 900)
			draw_point(e->rend, x, y);
		x += dx;
		y += dy;
	}
}

/*
 ** Calcul de la distance du rayon projete aux bords de la map.
 */

double	dist_rp(t_env *e)
{
	int		xmax;
	int		ymax;
	double	d_rp;

	xmax = 9;
	ymax = 9;
	if (e->cam.rpa < M_PI / 4)
	{
		e->cam.rpx = xmax - e->cam.xo;
		d_rp = tan(e->cam.a) * e->cam.rpx;
		e->cam.rpy = sqrt((d_rp * d_rp) - (e->cam.rpx * e->cam.rpx));
	}
	else
	{
		e->cam.rpy = ymax - e->cam.yo;
		d_rp = tan(M_PI / 2 - e->cam.a) * e->cam.rpy;
		e->cam.rpx = sqrt((d_rp * d_rp) - (e->cam.rpy * e->cam.rpy));
	}
	return (d_rp);
}

/*
 ** Detecte les intersections entre le rayon projete et les cases de la map.
 */

void	inter(t_env *e)
{
	double	d_rp;

	d_rp = dist_rp(e);
	(void)d_rp;
	/*while (d_rp-- >= 0)
	{
		printf("rpx : %lf", e->cam.rpx);
		printf("rpy : %lf", e->cam.rpy);
		printf("d_rp : %lf\n", d_rp);
	}*/
}

/*
 ** Trace un rayon par pixel de largeur d'ecran.
 ** soit 
 */

void	raycast(t_env *e)
{
	t_point	start;
	t_point	end;

	start.x = (int)e->cam.xo;
	start.y = (int)e->cam.yo;
	end.x = (int)e->cam.rpx;
	end.y = (int)e->cam.rpy;
	while (e->cam.a_cam + e->cam.rpa < e->cam.a_cam + e->cam.a)
	{
		inter(e);
		printf("rpa : %lf\n", e->cam.rpa);
		draw_line(e, start, end);
		e->cam.rpa += e->cam.a / POS_WIDTH;
	}
}



void	draw(t_env *e)
{
	SDL_SetRenderDrawColor(e->rend, 0, 0, 0, 0);
	SDL_RenderClear(e->rend);

	SDL_SetRenderDrawColor(e->rend, 255, 0, 0, 0);

	e->cam.xo = 7.5;
	e->cam.yo = 2.5;
	e->cam.a_cam = 0;
	e->cam.a = M_PI / 3;

	raycast(e);
	SDL_RenderPresent(e->rend);
}
