/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 08:07:38 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/15 02:12:05 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "wolf.h"

static void	move_vertical(t_env *e, double rt, int sens)
{
	if (sens == 1)
	{
		e->cam.posx += e->cam.dirx * rt;
		if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
			e->cam.posx -= e->cam.dirx * rt;
		e->cam.posy += e->cam.diry * rt;
		if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
			e->cam.posy -= e->cam.diry * rt;
	}
	else if (sens == 2)
	{
		e->cam.posx -= e->cam.dirx * rt;
		if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
			e->cam.posx += e->cam.dirx * rt;
		e->cam.posy -= e->cam.diry * rt;
		if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
			e->cam.posy += e->cam.diry * rt;
	}
}

static void	move_horiz(t_env *e, double rt, int sens)
{
	if (sens == 1)
	{
		e->cam.posx += (-(e->cam.diry)) * rt;
		if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
			e->cam.posx -= (-(e->cam.diry)) * rt;
		e->cam.posy += ((e->cam.dirx)) * rt;
		if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
			e->cam.posy -= ((e->cam.dirx)) * rt;
	}
	else if (sens == 2)
	{
		e->cam.posx += ((e->cam.diry)) * rt;
		if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
			e->cam.posx -= ((e->cam.diry)) * rt;
		e->cam.posy += (-(e->cam.dirx)) * rt;
		if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
			e->cam.posy -= (-(e->cam.dirx)) * rt;
	}
}

static void	handle_dir(t_env *e, double rt, int sens)
{
	double	o_dirx;
	double	o_planex;

	if (sens == 1)
	{
		o_dirx = e->cam.dirx;
		e->cam.dirx = e->cam.dirx * cos(rt) - e->cam.diry * sin(rt);
		e->cam.diry = o_dirx * sin(rt) + e->cam.diry * cos(rt);
		o_planex = e->cam.planx;
		e->cam.planx = e->cam.planx * cos(rt) - e->cam.plany * sin(rt);
		e->cam.plany = o_planex * sin(rt) + e->cam.plany * cos(rt);
	}
	if (sens == 2)
	{
		o_dirx = e->cam.dirx;
		e->cam.dirx = e->cam.dirx * cos(-rt) - e->cam.diry * sin(-rt);
		e->cam.diry = o_dirx * sin(-rt) + e->cam.diry * cos(-rt);
		o_planex = e->cam.planx;
		e->cam.planx = e->cam.planx * cos(-rt) - e->cam.plany * sin(-rt);
		e->cam.plany = o_planex * sin(-rt) + e->cam.plany * cos(-rt);
	}
}

void		set_keys(t_env *e)
{
	if (e->event.type == SDL_KEYDOWN)
	{
		(e->event.key.keysym.sym == SDLK_ESCAPE) ? exit(1) : 1;
		(e->event.key.keysym.sym == SDLK_UP) ? e->k.up = 1 : 1;
		(e->event.key.keysym.sym == SDLK_DOWN) ? e->k.down = 1 : 1;
		(e->event.key.keysym.sym == SDLK_LEFT) ? e->k.left = 1 : 1;
		(e->event.key.keysym.sym == SDLK_RIGHT) ? e->k.right = 1 : 1;
		(e->event.key.keysym.sym == SDLK_d) ? e->k.d = 1 : 1;
		(e->event.key.keysym.sym == SDLK_a) ? e->k.a = 1 : 1;
	}
	if (e->event.type == SDL_KEYUP)
	{
		(e->event.key.keysym.sym == SDLK_ESCAPE) ? exit(1) : 1;
		(e->event.key.keysym.sym == SDLK_UP) ? e->k.up = 0 : 1;
		(e->event.key.keysym.sym == SDLK_DOWN) ? e->k.down = 0 : 1;
		(e->event.key.keysym.sym == SDLK_LEFT) ? e->k.left = 0 : 1;
		(e->event.key.keysym.sym == SDLK_RIGHT) ? e->k.right = 0 : 1;
		(e->event.key.keysym.sym == SDLK_d) ? e->k.d = 0 : 1;
		(e->event.key.keysym.sym == SDLK_a) ? e->k.a = 0 : 1;
	}
	if (e->event.type == SDL_MOUSEMOTION)
		e->k.d = ((double)e->event.motion.x / e->w) * 2 - 1;
}

void		handle_event(t_env *e)
{
	set_keys(e);
	(e->k.esc) ? exit(1) : 1;
	(e->k.up) ? move_vertical(e, 0.3, 1) : 1;
	(e->k.down) ? move_vertical(e, 0.2, 2) : 1;
	(e->k.left) ? move_horiz(e, 0.2, 1) : 1;
	(e->k.right) ? move_horiz(e, 0.2, 2) : 1;
	(e->k.d > 0) ? handle_dir(e, e->k.d / 4, 2) :
		handle_dir(e, fabs(e->k.d) / 4, 1);
}
