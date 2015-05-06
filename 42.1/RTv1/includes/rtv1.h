/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:24:41 by jpirsch           #+#    #+#             */
/*   Updated: 2015/05/01 18:04:51 by sven             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define NAME "RTv1"
# define POS_X 0
# define POS_Y 0
# define POS_WIDTH 800
# define POS_HEIGHT 600
# define WALL_HEIGHT 300
# define SDL_WIN_FLAGS SDL_WINDOW_RESIZABLE
# define SDL_INIT_FLAGS SDL_INIT_VIDEO
# define GUN "ressources/gun.bmp"
# include "SDL/SDL.h"

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
}						t_point;

typedef struct			s_cam
{
	t_point				coord;
	t_point				ray;
}						t_cam;

typedef struct			s_sphere
{
	t_point				coord;
	double				ray;
}						t_sphere;

typedef struct			s_scene
{
	t_point				origin;
	t_sphere			sphere;
	t_cam				cam;
}						t_scene;

typedef struct			s_keys
{
	int					esc;
	int					up;
	int					down;
	int					left;
	int					right;
	int					a;
	int					d;
	double				mouse;
}						t_keys;

typedef struct			s_env
{
	SDL_Window			*win_sdl;
	SDL_Renderer		*rend;
	SDL_Event			event;
	SDL_Texture			*texture;
	SDL_Surface			*sprite;
	t_keys				k;
	t_scene				*scene;
	int					h;
	int					w;
	unsigned char		r;
}						t_env;

t_scene					*init_scene(void);
int						sdl_env(t_scene	*scene);
void					ft_init_sdl(t_env *e);
void					ft_create_win_sdl(t_env *e, int w, int h);
SDL_Renderer			*ft_init_renderer(t_env *e);
void					draw_point(t_env *e, int x, int y);
void					draw(t_env *e);
void					handle_event(t_env *e);
void					set_keys(t_env *e);
int						ft_free(t_env *e);
#endif
