/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 12:25:54 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/23 13:48:34 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

void			menu(t_env *e)
{
	SDL_Rect	dest;

	SDL_SetRenderDrawColor(e->rend, 0, 0, 0, 0);
	SDL_RenderClear(e->rend);
	if (e->texture)
	{
		dest.x = e->w / 4;
		dest.y = e->h / 4;
		dest.w = (e->sprite->w + e->w) / 8;
		dest.h = (e->sprite->h + e->h) / 8;
		SDL_SetTextureBlendMode(e->texture, SDL_BLENDMODE_BLEND);
		SDL_RenderCopy(e->rend, e->texture, NULL, &dest);
	}
	else
		ft_putendl_fd((char*)SDL_GetError(), 2);
	SDL_RenderPresent(e->rend);
}

int		menu_event(t_env *e)
{
	int	play;

	play = 0;
	if (e->event.type == SDL_MOUSEBUTTONDOWN)
		if (e->event.button.button == SDL_BUTTON_LEFT)
			if (e->event.button.x > e->w / 4 &&
				e->event.button.x < 3 * (e->w / 4) &&
				e->event.button.y < 3 * (e->h / 4) &&
				e->event.button.y > e->h / 4)
				e->r = 255;
	if (e->r == 255)
	{
		play = 1;
		SDL_Delay(200);
	}
	return ((play) ? 1 : 0);
}
