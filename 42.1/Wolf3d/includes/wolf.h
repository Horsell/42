/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:24:41 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/15 01:48:52 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define NAME "Wolf 3d"
# define POS_X 0
# define POS_Y 0
# define POS_WIDTH 800
# define POS_HEIGHT 600
# define WALL_HEIGHT 300
# define SDL_WIN_FLAGS SDL_WINDOW_RESIZABLE
# define SDL_INIT_FLAGS SDL_INIT_VIDEO
# include "SDL/SDL.h"

typedef struct			s_point
{
	double				x;
	double				y;
}						t_point;

typedef struct			s_play
{
	int					i;
	double				camerax;
	double				raypx;
	double				raypy;
	double				raydx;
	double				raydy;
	int					mapx;
	int					mapy;
	double				distmurx;
	double				distmury;
	double				dist2murx;
	double				dist2mury;
	double				longmur;
	int					erx;
	int					ery;
	int					touche;
	int					mvh;
	int					hmur;
}						t_play;

typedef struct			s_cam
{
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planx;
	double				plany;
}						t_cam;

typedef struct			s_keys
{
	int					esc;
	int					up;
	int					down;
	int					left;
	int					right;
	int					a;
	double				d;
}						t_keys;

typedef struct			s_env
{
	SDL_Window			*win_sdl;
	SDL_Renderer		*rend;
	SDL_Event			event;
	SDL_Texture			*texture;
	SDL_Surface			*sprite;
	t_keys				k;
	int					h;
	int					w;
	int					**map;
	t_cam				cam;
}						t_env;

int						**parse(int fd);
int						sdl_env(int	**map);
void					ft_init_sdl(t_env *e);
void					ft_create_win_sdl(t_env *e, int w, int h)
;
SDL_Renderer			*ft_init_renderer(t_env *e);
void					draw_point(t_env *e, int x, int y);
void					load_image(t_env *e);
void					put_sprite(t_env *e);
void					draw(t_env *e);
void					handle_event(t_env *e);
int						ft_free(t_env *e);
#endif
