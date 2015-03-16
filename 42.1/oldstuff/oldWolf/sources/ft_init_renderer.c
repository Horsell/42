/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_renderer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 12:43:38 by jpirsch           #+#    #+#             */
/*   Updated: 2015/02/08 04:00:15 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf.h"

SDL_Renderer	*ft_init_renderer(SDL_Window *win_sdl)
{
	SDL_Renderer *g_renderer;

	if ((g_renderer = SDL_CreateRenderer(win_sdl, -1, \
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC \
					)) == NULL)
	{
		ft_putstr_fd("SDL_Create_Renderer error ", 2);
		ft_putendl_fd((char*)SDL_GetError(), 2);
//		ft_free();
		exit(-1);
	}
	return (g_renderer);
}
