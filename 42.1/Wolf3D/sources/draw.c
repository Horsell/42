/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:13:47 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/14 11:51:16 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	draw(t_env *e)
{
	t_point			a;
	t_point			b;

	a.x = 10;
	a.y = 10;
	b.x = 30;
	b.y = 30;
	SDL_SetRenderDrawColor(e->rend, 0, 0, 0, 0);
	SDL_RenderClear(e->rend);
	SDL_SetRenderDrawColor(e->rend, 255, 0, 0, 0);
	draw_line(e, a, b);
	SDL_RenderPresent(e->rend);
}
