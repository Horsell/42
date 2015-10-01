/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 17:33:45 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/01 09:55:10 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "arkanoid.h"

static void	ft_glrect(float x1, float y1, float width, float height)
{
	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x1 + width, y1);
	glVertex2f(x1 + width, y1 + height);
	glVertex2f(x1, y1 + height);
	glEnd();
}

void		draw_ball(t_env *e)
{
	const float	full_angle = 2.0f * 3.141592654f;
	int			nbseg;
	int			i;

	nbseg = 100;
	i = 0;
//	e->ball_x += 0.5;
//	e->ball_y += 0.5;
	glBegin(GL_POLYGON);
	glColor3ub(190, 190, 190);
	while (i < nbseg)
	{
		glVertex2f(e->ball_rad * (cos(i * full_angle / nbseg)) + e->ball_x,
			e->ball_rad * (sin(i * full_angle / nbseg)) + e->ball_y);
		++i;
	}
	glEnd();
}

void		draw(t_env *e)
{
	int	width = 800;
	int	height = 600;

	glfwGetFramebufferSize(e->window, &width, &height);
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(255, 0, 255);
	ft_glrect(-0.3, -0.4, 0.5, 0.3);
//	draw_ball(e);
	event(e);
	glfwSwapBuffers(e->window);
	glfwPollEvents();
}
