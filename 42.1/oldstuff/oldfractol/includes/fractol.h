/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 02:21:11 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/11 21:27:54 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					size_line;
	int					depth;
	int					endian;
	double				decalx;
	double				decaly;
	double				x;
	double				y;
	double				zoom;
	int					fract_type;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_env;

typedef struct			s_pt
{
	double				x;
	double				y;
}						t_pt;

void					px_to_img(t_env *e, int x, int y);
void					print_state(t_env *e);
void					env(int	fract);
void					draw(t_env *e);
void					draw_tree(t_env *e, t_pt start, double angle,
						int depth);
#endif
