/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:24:41 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/14 11:49:29 by jpirsch          ###   ########.fr       */
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

typedef struct				s_point
{
		int					x;
		int					y;
		int					z;
		unsigned char		r;
		unsigned char		g;
		unsigned char		b;
		
}							t_point;

typedef struct				s_env
{
	SDL_Window				*win_sdl;
	SDL_Renderer			*rend;
	SDL_Event				event;
	int						**map;
}							t_env;

int							**parse(int fd);
void						ft_init_sdl(void);
void						ft_create_win_sdl(SDL_Window **win_sdl, int w,\
												int h);
SDL_Renderer				*ft_init_renderer(SDL_Window *win_sdl);
void						sdl_env(int	**map);
void						draw_point(SDL_Renderer *rend, int x, int y);
void						draw(t_env *e);
void						handle_event(t_env *e);

#endif
