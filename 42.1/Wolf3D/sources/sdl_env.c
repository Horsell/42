/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:07:55 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/18 06:34:01 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf.h"

void	init_cam(t_cam *cam)
{
	cam->xo = 2.5;
	cam->yo = 7.5;
	cam->a = M_PI / 3;
	cam->a_cam = 0;
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
