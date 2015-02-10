/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_env.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 02:21:11 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/09 02:49:37 by jpirsch          ###   ########.fr       */
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
	int					decalx;
	int					decaly;
	int					zoom;
	int					fract_type;
	unsigned char		R;
	unsigned char		G;
	unsigned char		B;
}						t_env;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;
//mlx_env
void					px_to_img(t_env *e, int x, int y);
void					print_state(t_env *e);
void					env(int fract_type);
//drawline
void					draw(t_env *e);

#endif
