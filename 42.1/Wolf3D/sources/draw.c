/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:13:47 by jpirsch           #+#    #+#             */
/*   Updated: 2015/02/08 02:55:10 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "libft.h"
#include "wolf.h"

void	draw_vertical(t_env *e, t_point start, t_point end)
{
	if (start.y < 0)
		start.y = 0;
	if (end.y > POS_HEIGHT)
		end.y = POS_HEIGHT;
	SDL_SetRenderDrawColor(e->rend, 255, 0, 0, 0);
	while (start.y < end.y)
	{
		draw_point(e->rend, start.x, start.y);
		start.y++;
	}
	SDL_SetRenderDrawColor(e->rend, 128, 128, 128, 0);
	while (start.y < end.y)
	{
		draw_point(e->rend, start.x, start.y);
		start.y++;
	}
}

void	color(t_env *e, t_play *p, int i)
{
	t_point	start;
	t_point	end;

	start.x = i;
	start.y = (POS_HEIGHT / 2) - (p->hmur / 2);
	end.x = i;
	end.y = (POS_HEIGHT / 2) + (p->hmur / 2);
	if (i == 400)
		start.y = 0, end.y = POS_HEIGHT;
	draw_vertical(e, start, end);
}

void    colone(t_env *e, t_play *p, int i)
{
	while (e->map[p->mapy][p->mapx] == 0)
	{
		if (p->distmurx < p->distmury)
		{
			p->distmurx += p->dist2murx;
			p->mapx += p->erx;
			p->mvh = 0;
		}
		else
		{
			p->distmury += p->dist2mury;
			p->mapy += p->ery;
			p->mvh = 1;
		}
	}
	if (p->mvh == 0)
		p->longmur = fabs((p->mapx - p->raypx + (1 - p->erx) / 2) / p->raydx);
	else
		p->longmur = fabs((p->mapy - p->raypy + (1 - p->ery) / 2) / p->raydy);
	p->hmur = abs((int)(POS_HEIGHT / p->longmur));
	color(e, p, i);
}

void    get_d(t_env *e, int i)
{
	t_play        p;

	p.mvh = 0;
	while (i < POS_WIDTH)
	{
		p.camerax = 2 * i / (double)(POS_WIDTH) - 1;
		p.raypx = e->cam.posx;
		p.raypy = e->cam.posy;
		p.raydx = e->cam.dirx + e->cam.planx * p.camerax;
		p.raydy = e->cam.diry + e->cam.plany * p.camerax;
		p.mapx = (int)p.raypx;
		p.mapy = (int)p.raypy;
		p.dist2murx = sqrt(1 + (p.raydy * p.raydy) / (p.raydx * p.raydx));
		p.dist2mury = sqrt(1 + (p.raydx * p.raydx) / (p.raydy * p.raydy));
		p.touche = 0;
		if (p.raydx < 0 && (p.erx = -1))
			p.distmurx = (p.raypx - p.mapx) * p.dist2murx;
		else if ((p.erx = 1))
			p.distmurx = (p.mapx + 1.0 - p.raypx) * p.dist2murx;
		if (p.raydy < 0 && (p.ery = -1))
			p.distmury = (p.raypy - p.mapy) * p.dist2mury;
		else if ((p.ery = 1))
			p.distmury = (p.mapy + 1.0 - p.raypy) * p.dist2mury;
		colone(e, &p, i++);
	}
}

//		h = (692 * WALL_HEIGHT) / d;

void	draw(t_env *e)
{
	SDL_SetRenderDrawColor(e->rend, 0, 0, 0, 0);
	SDL_RenderClear(e->rend);
	get_d(e, 0);
	SDL_RenderPresent(e->rend);
}
