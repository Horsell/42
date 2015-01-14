/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 08:07:38 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/14 11:50:00 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	handle_event(t_env *e)
{
	if (e->event.type == SDL_KEYDOWN)
	{
		if (e->event.key.keysym.sym == SDLK_ESCAPE)
			exit(1);
	}
}
