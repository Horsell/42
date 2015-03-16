/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 01:11:40 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/14 23:05:44 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf.h"

void	load_image(t_env *e)
{
	e->sprite = SDL_LoadBMP("ressources/gun.bmp");
	if (e->sprite)
		e->texture = SDL_CreateTextureFromSurface(e->rend, e->sprite);
	else
		ft_putendl_fd((char*)SDL_GetError(), 2);
}

void	put_sprite(t_env *e)
{
	SDL_Rect	dest;

	if (e->texture)
	{
		dest.x = (e->w - (e->sprite->w + e->w) / 8) / 2;
		dest.y = e->h - (e->sprite->h + e->h) / 8;
		dest.w = (e->sprite->w + e->w) / 8;
		dest.h = (e->sprite->h + e->h) / 8;
		SDL_RenderCopy(e->rend, e->texture, NULL, &dest);
	}
	else
		ft_putendl_fd((char*)SDL_GetError(), 2);
}
