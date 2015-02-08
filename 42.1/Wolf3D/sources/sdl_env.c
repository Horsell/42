/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:07:55 by jpirsch           #+#    #+#             */
/*   Updated: 2015/02/08 02:01:15 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf.h"

void	init_cam(t_cam *cam)
{
	cam->posx = 8;
	cam->posy = 5;
	cam->dirx = -1;
	cam->diry = 0;
	cam->planx = 0;
	cam->plany = 0.66;
}

void	sdl_env(int	**map)
{
	t_env	e;

	ft_init_sdl();
	ft_create_win_sdl(&e.win_sdl, 0, 0);
	e.rend = ft_init_renderer(e.win_sdl);
	e.map = map;
	init_cam(&e.cam);
	while (1)
	{
		while (SDL_PollEvent(&e.event))
		{
			handle_event(&e);
			draw(&e);
		}
	}
}
