/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 08:07:38 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/18 06:20:30 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "wolf.h"

void	handle_event(t_env *e)
{
	if (e->event.type == SDL_KEYDOWN)
	{
		if (e->event.key.keysym.sym == SDLK_ESCAPE)
			exit(1);
		if (e->event.key.keysym.sym == SDLK_UP)
			e->cam.xo += 0.5;
		if (e->event.key.keysym.sym == SDLK_DOWN)
			e->cam.xo -= 0.5;
		if (e->event.key.keysym.sym == SDLK_LEFT)
			e->cam.yo += 0.5;
		if (e->event.key.keysym.sym == SDLK_RIGHT)
			e->cam.yo -= 0.5;
		if (e->event.key.keysym.sym == SDLK_a)
			e->cam.a_cam += M_PI / 12;
		if (e->event.key.keysym.sym == SDLK_d)
			e->cam.a_cam -= M_PI / 12;
	}
}
