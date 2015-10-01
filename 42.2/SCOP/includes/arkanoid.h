/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 15:36:32 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/01 04:52:17 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H
# include <GLFW/glfw3.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

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
