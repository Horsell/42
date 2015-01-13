/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:24:41 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/13 13:02:28 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
#include "SDL/SDL.h"
# define WOLF_H
# define NAME "Wolf 3d"
# define POS_X 0
# define POS_Y 0
# define POS_WIDTH 800
# define POS_HEIGHT 600
# define SDL_WIN_FLAGS SDL_WINDOW_SHOWN
# define SDL_INIT_FLAGS SDL_INIT_VIDEO

void			ft_init_sdl(void);
void			ft_create_win_sdl(SDL_Window **win_sdl, int w, int h);
SDL_Renderer*	ft_getrenderer(void);
void			ft_init_renderer(SDL_Window	 *win_sdl);
void			draw_point(int x, int y);
int				**parse(int fd);

#endif
