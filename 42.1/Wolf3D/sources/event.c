/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 08:07:38 by jpirsch           #+#    #+#             */
/*   Updated: 2015/02/08 03:00:43 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "wolf.h"

void	move_up(t_env *e, double rt)
{
	e->cam.posx += e->cam.dirx * rt;
	if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
		e->cam.posx -= e->cam.dirx * rt;
	e->cam.posy += e->cam.diry * rt;
	if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
		e->cam.posy -= e->cam.diry * rt;
}

void	move_down(t_env *e, double rt)
{
	e->cam.posx -= e->cam.dirx * rt;
	if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
		e->cam.posx += e->cam.dirx * rt;
	e->cam.posy -= e->cam.diry * rt;
	if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
		e->cam.posy += e->cam.diry * rt;
}

void	move_left(t_env *e, double rt)
{
	e->cam.posx += (-(e->cam.diry)) * rt;
	if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
		e->cam.posx -= (-(e->cam.diry)) * rt;
	e->cam.posy += ((e->cam.dirx)) * rt;
	if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
		e->cam.posy -= ((e->cam.dirx)) * rt;
}

void	move_right(t_env *e, double rt)
{
	e->cam.posx += ((e->cam.diry)) * rt;
	if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
		e->cam.posx -= ((e->cam.diry)) * rt;
	e->cam.posy += (-(e->cam.dirx)) * rt;
	if (e->map[(int)e->cam.posy][(int)e->cam.posx] == 1)
		e->cam.posy -= (-(e->cam.dirx)) * rt;
}

void    handle_dir(t_env *e, double rt)
{
	double    o_dirx;
	double    o_planex;

	if (e->event.key.keysym.sym == SDLK_a)
	{
		o_dirx = e->cam.dirx;
		e->cam.dirx = e->cam.dirx * cos(rt) - e->cam.diry * sin(rt);
		e->cam.diry = o_dirx * sin(rt) + e->cam.diry * cos(rt);
		o_planex = e->cam.planx;
		e->cam.planx = e->cam.planx * cos(rt) - e->cam.plany * sin(rt);
		e->cam.plany = o_planex * sin(rt) + e->cam.plany * cos(rt);
	}
	if (e->event.key.keysym.sym == SDLK_d)
	{
		o_dirx = e->cam.dirx;
		e->cam.dirx = e->cam.dirx * cos(-rt) - e->cam.diry * sin(-rt);
		e->cam.diry = o_dirx * sin(-rt) + e->cam.diry * cos(-rt);
		o_planex = e->cam.planx;
		e->cam.planx = e->cam.planx * cos(-rt) - e->cam.plany * sin(-rt);
		e->cam.plany = o_planex * sin(-rt) + e->cam.plany * cos(-rt);
	}
}

void	handle_event(t_env *e)
{
	if (e->event.type == SDL_KEYDOWN)
	{
		(e->event.key.keysym.sym == SDLK_ESCAPE) ? exit(1) : 1;
		(e->event.key.keysym.sym == SDLK_UP) ? move_up(e, 0.5) : 1;
		(e->event.key.keysym.sym == SDLK_DOWN) ? move_down(e, 0.3) : 1;
		(e->event.key.keysym.sym == SDLK_LEFT) ? move_left(e, 0.3) : 1;
		(e->event.key.keysym.sym == SDLK_RIGHT) ? move_right(e, 0.3) : 1;
		handle_dir(e, 0.1);
	}
}
