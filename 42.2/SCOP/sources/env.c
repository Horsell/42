/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 17:32:33 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/02 16:40:54 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void error_callback(int error, const char *description)
{
	ft_putendl_fd((char*)description, 2);
	(void)error;
}

void		init_vars(t_env *e)
{
	e->ball_x = 10;
	e->ball_y = 4;
	e->ball_rad = 10;
}

t_env		*init_glfw_env(void)
{
	t_env	*e;

	if (!(e = malloc(sizeof(t_env))))
		return (NULL);
	init_vars(e);
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return (NULL);
	e->window = glfwCreateWindow(640, 480, "Arkanoid", NULL, NULL);
	if (!e->window)
	{
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(e->window);
	return (e);
}

void		event(t_env *e)
{
	if (glfwGetKey(e->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(e->window, GL_TRUE);
	if (glfwGetKey(e->window, GLFW_KEY_LEFT) == GLFW_PRESS)
		e->ball_x -= 0.05;
	if (glfwGetKey(e->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		e->ball_x += 0.05;
	if (glfwGetKey(e->window, GLFW_KEY_UP) == GLFW_PRESS)
		e->ball_rad += 0.5;
	if (glfwGetKey(e->window, GLFW_KEY_DOWN) == GLFW_PRESS)
		e->ball_rad -= 0.5;
}

void		ft_quit(t_env *e)
{
	glfwDestroyWindow(e->window);
	glfwTerminate();
}
