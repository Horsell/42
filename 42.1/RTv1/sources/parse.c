/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sven <jpirsch@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 23:55:12 by sven              #+#    #+#             */
/*   Updated: 2015/05/11 20:45:51 by sven             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rtv1.h"


t_scene		*init_scene()
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	scene->sphere.coord.x = 10;
	scene->sphere.coord.y = 10;
	scene->sphere.coord.z = 10;
	scene->sphere.rad = 5;
	scene->cam.r0.x = 0;
	scene->cam.r0.y = 0;
	scene->cam.r0.z = 0;
//	RD = malloc(sizeof(t_point) * POS_WIDTH * POS_HEIGHT);
	scene->cam.ray = malloc(sizeof(t_point) * POS_WIDTH * POS_HEIGHT);
//	RD[0].x = 1;
//	RD[0].y = 0;
//	RD[0].z = 1;
//	ft_putnbr(RD[0].x);
	return (scene);
}
