/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:24:41 by jpirsch           #+#    #+#             */
/*   Updated: 2015/05/11 20:19:56 by sven             ###   ########.fr       */
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
# define RD e->scene->cam.ray
# define XC e->scene->sphere.coord.x
# define YC e->scene->sphere.coord.y
# define ZC e->scene->sphere.coord.z
# define SR e->scene->sphere.rad
# include "SDL/SDL.h"
# include <math.h>

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
	char				r;
	char				g;
	char				b;
}						t_point;

typedef struct			s_mat
{
	t_point				a;
	t_point				b;
	t_point				c;
}						t_mat;

typedef struct			s_cam
{
	t_point				r0;
	t_point				*ray;
}						t_cam;

typedef struct			s_sphere
{
	t_point				coord;
	double				rad;
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
	t_mat				id;
	t_mat				rot;
}						t_env;

t_scene					*init_scene(void);
int						sdl_env(t_scene	*scene);
void					ft_init_sdl(t_env *e);
void					ft_create_win_sdl(t_env *e, int w, int h);
SDL_Renderer			*ft_init_renderer(t_env *e);
void					draw_point(t_env *e, t_point *pt);
void					draw(t_env *e);
void					handle_event(t_env *e);
void					set_keys(t_env *e);
int						ft_free(t_env *e);
t_mat					matrix_product(t_mat mat_a, t_mat mat_b);
t_mat					matrix_vector_product(t_mat mat, t_point ray);
void					matrix_init_id(t_mat *mat);
void					matrix_init_rot(t_mat *mat);
void					set_ray(t_env *e, int i, int j);
void					matrix_init_rotx(t_mat *mat, float theta);
void					matrix_init_roty(t_mat *mat, float theta);
void					matrix_init_rotz(t_mat *mat, float theta);
#endif
