/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:24:41 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/04 13:52:32 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define NAME "RTv1"
# define POS_X 0
# define POS_Y 0
# define POS_WIDTH 800
# define POS_HEIGHT 600
# define SDL_WIN_FLAGS SDL_WINDOW_RESIZABLE
# define SDL_INIT_FLAGS SDL_INIT_VIDEO
# include <mlx.h>

typedef struct			s_cam
{
	double				posx;
	double				posy;
	double				posz;
	double				rotx;
	double				roty;
	double				rotz;
}						t_cam;

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

typedef struct			s_mat
{
	int					a;
	int					b;
	int					c;
	int					d;
	int					e;
	int					f;
	int					g;
	int					h;
	int					i;
	int					j;
	int					k;
	int					l;
	int					m;
	int					n;
	int					o;
	int					p;
}						t_mat;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					size_line;
	int					depth;
	int					endian;
	int					**map;
	int					proj;
	double				scale;
	double				cte1;
	int					decalx;
	int					decaly;
	int					zoom;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
	t_keys				key;
}						t_env;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	unsigned int		color;
}						t_point;

/*
** hook
*/
void					init_t_key(t_keys *key);
int						key_press(int keycode, t_env *e);
int						key_release(int keycode, t_env *e);
int						loop_hook(t_env *e);
/*
** mlx_env
*/
void					px_to_img(t_env *e, int x, int y);
void					print_state(t_env *e);
void					env();
/*
** coord
*/
void					init_point(t_point *point, int x, int y, int z);
t_point					**malloc_grid(int **map);
t_point					**map_to_point(t_env *e);
/*
** drawline
*/
void					draw(t_env *e);
/*
** parse
*/
int						**parse(int fd);

#endif
