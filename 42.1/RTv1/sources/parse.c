/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sven <jpirsch@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 23:55:12 by sven              #+#    #+#             */
/*   Updated: 2015/04/29 00:01:46 by sven             ###   ########.fr       */
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
	scene->sphere.ray = 50;
	scene->cam.coord.x = 0;
	scene->cam.coord.y = 0;
	scene->cam.coord.z = 0;
	return (scene);
}
