/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 11:44:32 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/13 12:55:27 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "SDL/SDL.h"
#include "libft.h"
#include "wolf.h"

void	draw_point(int x, int y)
{
	if (SDL_RenderDrawPoint(ft_getrenderer(), x, y) < 0)
	{
		ft_putstr_fd("SetRenderDrawPoint error ", 2);
		ft_putendl_fd((char*)SDL_GetError(), 2);
	//	ft_free();
		exit(-1);
	}
}
