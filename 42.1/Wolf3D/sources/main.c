/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/12 11:49:56 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "wolf.h"
#include "SDL.h"

int		main()
{
	int		fd;
	int		**map;
	SDL_Window	*win_sdl;

	fd = open("map", O_RDONLY);
	map = parse(fd);
	ft_putstr("map[0][0] : ");
	ft_putnbr(map[0][0]);
    SDL_Init(SDL_INIT_VIDEO);
	win_sdl = SDL_CreateWindow("Wolf", 0, 0, 800, 600, SDL_WINDOW_SHOWN);
	(void)win_sdl;
	sleep(100);
    SDL_Quit();
	return (0);
}
