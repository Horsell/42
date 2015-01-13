/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 11:26:17 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/13 12:51:16 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "SDL/SDL.h"
#include "libft.h"
#include "wolf.h"

void	ft_init_sdl(void)
{
	if (SDL_Init(SDL_INIT_FLAGS) < 0)
	{
		ft_putstr_fd("SDL_Init error ", 2);
		ft_putendl_fd((char*)SDL_GetError(), 2);
		//ft_free();
		exit(-1);
	}
}	

void	ft_create_win_sdl(SDL_Window **win_sdl, int w, int h)
{
	if (w <= 0 || h <= 0)
	{
		if ((*win_sdl = SDL_CreateWindow(NAME, POS_X, POS_Y, POS_WIDTH, \
						POS_HEIGHT, SDL_WIN_FLAGS)) == NULL)
		{
			ft_putstr_fd("SDL_CreateWindow error ", 2);
			ft_putendl_fd((char*)SDL_GetError(), 2);
			//ft_free();
			exit(-1);
		}
	}
	else
	{
		if ((*win_sdl = SDL_CreateWindow(NAME, POS_X, POS_Y, w, \
						h, SDL_WIN_FLAGS)) == NULL)
		{
			ft_putstr_fd("SDL_CreateWindow error ", 2);
			ft_putendl_fd((char*)SDL_GetError(), 2);
			//ft_free();
			exit(-1);
		}
	}
}
