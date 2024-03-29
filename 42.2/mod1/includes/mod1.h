/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 15:36:32 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/02 16:06:22 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H
# include <glfw3.h>
# include <iostream>

typedef struct	s_env
{
	GLFWwindow	*window;
	float		ball_x;
	float		ball_y;
	float		ball_rad;
}				t_env;

t_env			*init_glfw_env(void);
void			draw(t_env *e);
void			event(t_env *e);
void			ft_quit(t_env *e);
#endif
