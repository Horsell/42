/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_env.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 02:21:11 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/03 01:54:29 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

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
	int					decalx;
	int					decaly;
	int					zoom;
	unsigned char		R;
	unsigned char		G;
	unsigned char		B;
}						t_env;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	unsigned int		color;
}						t_point;
//mlx_env
void					px_to_img(t_env *e, int x, int y);
void					print_state(t_env *e);
void					env(int **map);
//coord
void					init_point(t_point *point, int x, int y, int z);
t_point					**malloc_grid(int **map);
t_point					**map_to_point(t_env *e);
//drawline
void					draw_grid(t_env *e);
//parse
int						**parse(int fd);

#endif
