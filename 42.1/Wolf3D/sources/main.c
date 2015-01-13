/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/13 14:52:58 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "wolf.h"
//#include "SDL/SDL.h"

void	draw_line(int x1, int y1, int x2, int y2)
{
	int i;

	i = 0;
	while (i < 300)
	{
		draw_point(i, y1);
		i++;
	}
	(void)x1;
	(void)x2;
	(void)y2;
}

int		main()
{
	int		fd;
	int		**map;
	SDL_Window	*win_sdl;
	int		i;

	fd = open("map", O_RDONLY);
	map = parse(fd);

	ft_init_sdl();
	ft_create_win_sdl(&win_sdl, 0, 0);
	ft_init_renderer(win_sdl);
	(void)map;
	i = 0;
	while (i < 300)
	{
		draw_line(0, i, 0, 0);
		i++;
	}
	SDL_RenderPresent(ft_getrenderer());
	sleep(10);
	return (0);
}
