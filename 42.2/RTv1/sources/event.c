/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 08:07:38 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/29 00:05:51 by sven             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rtv1.h"

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
		(e->event.key.keysym.sym == SDLK_UP) ? e->k.up = 0 : 1;
		(e->event.key.keysym.sym == SDLK_DOWN) ? e->k.down = 0 : 1;
		(e->event.key.keysym.sym == SDLK_LEFT) ? e->k.left = 0 : 1;
		(e->event.key.keysym.sym == SDLK_RIGHT) ? e->k.right = 0 : 1;
		(e->event.key.keysym.sym == SDLK_d) ? e->k.d = 0 : 1;
		(e->event.key.keysym.sym == SDLK_a) ? e->k.a = 0 : 1;
	}
/*	if (e->event.type == SDL_MOUSEMOTION)
		e->k.mouse = (((double)e->event.motion.xrel) / (e->w / 8));
	if (e->event.type == SDL_MOUSEBUTTONDOWN)
		if (e->event.button.button == SDL_BUTTON_LEFT)
			shoot(e);
	(e->event.key.keysym.sym == SDLK_SPACE) ? shoot(e) : 1;*/
}

void		handle_event(t_env *e)
{
	set_keys(e);
	(e->k.up) ? 1 : 1;
	(e->k.down) ? 1 : 1;
	(e->k.left) ? 1 : 1;
	(e->k.right) ? 1 : 1;
	(e->k.a) ? 1 : 1;
	(e->k.d) ? 1 : 1;
	(e->k.mouse > 0) ? 1 : 1;
	(e->k.esc) ? ft_free(e) : 1;
}
