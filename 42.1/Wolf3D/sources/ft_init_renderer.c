/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_renderer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 12:43:38 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/13 12:55:21 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "SDL/SDL.h"
#include "libft.h"
#include "wolf.h"

SDL_Renderer* g_renderer;

SDL_Renderer* ft_getrenderer(void)
{
	return (g_renderer);
}

void			ft_init_renderer(SDL_Window	 *win_sdl)
{
	if ((g_renderer = SDL_CreateRenderer(win_sdl, -1, \
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC \
					)) == NULL)
	{
		ft_putstr_fd("SDL_Create_Renderer error ", 2);
		ft_putendl_fd((char*)SDL_GetError(), 2);
//		ft_free();
		exit(-1);
	}
}
