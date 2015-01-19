/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:13:47 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/18 06:33:31 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
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
			draw_point(e->rend, (int)x, (int)y);
		x += dx;
		y += dy;
	}
}
/*
** Calculate distance of ray to map bound.
*/
double	dist_rp(t_cam *cam)
{
	int		xmax;
	int		ymax;
	double	d_rp;

	xmax = 9;
	ymax = 0;
	if (cam->rpa < M_PI / 4)
	{
		cam->rpx = xmax - cam->xo;
		cam->rpy = tan(cam->rpa) * cam->rpx;
		d_rp = sqrt((cam->rpy * cam->rpy) + (cam->rpx * cam->rpx));
	}
	else if (cam->rpa < M_PI / 2)
	{
		cam->rpy = ymax - cam->yo;
		cam->rpx = tan(M_PI / 2 - cam->rpa) * cam->rpy;
		d_rp = sqrt((cam->rpx * cam->rpx) + (cam->rpy * cam->rpy));
	}
	else if (cam->rpa < 3 * (M_PI / 4))
	{
		cam->rpy = ymax - cam->yo;
		cam->rpx = tan(M_PI / 2 - cam->rpa) * cam->rpy;
		d_rp = sqrt((cam->rpx * cam->rpx) + (cam->rpy * cam->rpy));
	}
	return (d_rp);
}
/*
** Detects intersect of ray and map walls.
*/
double	inter(t_env *e)
{
	double	d_rp;

	d_rp = dist_rp(&e->cam);
	(void)d_rp;
	/*while (d_rp-- >= 0)
	{
	}*/
	//printf("d_rp : %lf	", d_rp);
	return (d_rp);
}
/*
** Trace a ray for each pixel in screen width.
*/
void	raycast(t_env *e)
{
	int	i;
	t_point start;
	t_point end;
	double d;
	double h;

	i = 800;
	e->cam.rpa = 0;
	while (e->cam.a_cam + e->cam.rpa < e->cam.a_cam + e->cam.a)
	{
		d = 300 * inter(e);
		h = (/*692*/200 * WALL_HEIGHT) / d;
		start.x = i;
		start.y = (POS_HEIGHT / 2) - (h / 2);
		end.x = i;
		end.y = (POS_HEIGHT / 2) + (h / 2);
		draw_line(e, start, end);
		e->cam.rpa += e->cam.a / POS_WIDTH;
		i--;
	}
}

void	draw(t_env *e)
{
	SDL_SetRenderDrawColor(e->rend, 0, 0, 0, 0);
	SDL_RenderClear(e->rend);
	SDL_SetRenderDrawColor(e->rend, 255, 0, 0, 0);
			printf("a_cam = %lf\n", e->cam.a_cam);
	raycast(e);
	SDL_RenderPresent(e->rend);
}
