/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:13:47 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/20 09:38:56 by jpirsch          ###   ########.fr       */
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

void	draw_vertical(t_env *e, t_point start, t_point end)
{
	while (start.y < end.y)
	{
		draw_point(e->rend, start.x, start.y);
		start.y++;
	}
}

int		distx(t_env *e)
{
	int	distx;
	int	Ay;
	int	Ax;
	int	Ya;
	int	Xa;

	if (e->cam.rpa > 0 && e->cam.rpa < M_PI)
	{
		Ay = floor(64 * e->cam.yo) / 64 - 1;
		Ya = -64;
	}
	else if (e->cam.rpa > M_PI)
	{
		Ay = floor(64 * e->cam.yo) / 64;
		Ya = 64;
	}
	Ax = e->cam.xo + (e->cam.yo - Ay) / tan(e->cam.rpa);
	Xa = 64 / tan(e->cam.rpa);
	while (Ay / 64 <= 10 && Ay / 64 >= 0 && Ax / 64 <= 10 && Ax / 64 >= 0)
	{
		if (e->map[Ay / 64][Ax / 64] == 1)
			break;
		Ay += Ya;
		Ax += Xa;
	}
	distx = sqrt(pow(Ay, 2) + pow(Ax, 2));
	return (distx);
}

int		disty(t_env *e)
{
	int	disty;
	int	Ay;
	int	Ax;
	int	Ya;
	int	Xa;

	if (e->cam.rpa > M_PI / 2 && e->cam.rpa < 3 * (M_PI / 2))
	{
		Ax = floor(64 * e->cam.xo) / 64 - 1;
		Xa = -64;
	}
	else if (e->cam.rpa > 3 * (M_PI / 2) || (e->cam.rpa > 0 && e->cam.rpa < M_PI / 2))
	{
		Ax = floor(64 * e->cam.xo) / 64;
		Xa = 64;
	}
	Ay = e->cam.yo + (e->cam.xo - Ax) * tan(e->cam.rpa);
	Ya = 64 / tan(e->cam.rpa);
	while (Ay / 64 <= 10 && Ay / 64 >= 0 && Ax / 64 <= 10 && Ax / 64 >= 0)
	{
		if (e->map[Ay / 64][Ax / 64] == 1)
			break;
		Ay += Ya;
		Ax += Xa;
	}
	disty = sqrt(pow(Ay, 2) + pow(Ax, 2));
	return (disty);
}

int		dist(t_env *e)
{
	int d1;
	int d2;

	d1 = distx(e);
	if ((d2 = disty(e)) > d1)
		return (d2);
	return (d1);
}

/*
** Trace a ray for each pixel in screen width.
*/
void	raycast(t_env *e)
{
	int	i;
	t_point start;
	t_point end;
	int d;
	int h;

	i = POS_WIDTH;
	e->cam.rpa = e->cam.a_cam;
	while (e->cam.a_cam + e->cam.rpa < e->cam.a_cam + e->cam.a)
	{
		d = dist(e);
		h = (692 * WALL_HEIGHT) / d;
		start.x = i;
		start.y = (POS_HEIGHT / 2) - (h / 2);
		end.x = i;
		end.y = (POS_HEIGHT / 2) + (h / 2);
		draw_vertical(e, start, end);
		e->cam.rpa += e->cam.a / POS_WIDTH;
		i--;
	}
}

void	draw(t_env *e)
{
	SDL_SetRenderDrawColor(e->rend, 0, 0, 0, 0);
	SDL_RenderClear(e->rend);
	SDL_SetRenderDrawColor(e->rend, 255, 0, 0, 0);
			//printf("a_cam = %lf\n", e->cam.a_cam);
			//printf("xo = %d\n", e->cam.xo);
			//printf("yo = %d\n", e->cam.yo);
	raycast(e);
	SDL_RenderPresent(e->rend);
}
