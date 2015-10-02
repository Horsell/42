/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 17:31:32 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/01 04:51:52 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int		main(void)
{
	t_env	*e;

	if (!(e = init_glfw_env()))
		return (-1);
	while (!glfwWindowShouldClose(e->window))
		draw(e);
	ft_quit(e);
	return (0);
}