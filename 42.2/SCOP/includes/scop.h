/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 16:38:06 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/02 16:40:18 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# include <glfw3.h>
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
