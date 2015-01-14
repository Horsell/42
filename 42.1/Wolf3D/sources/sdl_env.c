/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:07:55 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/14 11:49:56 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf.h"

void	sdl_env(int	**map)
{
	t_env	e;

	ft_init_sdl();
	ft_create_win_sdl(&e.win_sdl, 0, 0);
	e.rend = ft_init_renderer(e.win_sdl);
	e.map = map;
	while (1)
	{
		while (SDL_PollEvent(&e.event))
		{
			handle_event(&e);
			draw(&e);
		}
	}
	(void)map;
}
