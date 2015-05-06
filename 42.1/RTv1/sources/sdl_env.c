/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:07:55 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/29 00:12:57 by sven             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rtv1.h"

static void		init_keys(t_env *e)
{
	e->k.esc = 0;
	e->k.up = 0;
	e->k.down = 0;
	e->k.left = 0;
	e->k.right = 0;
	e->k.a = 0;
	e->k.d = 0;
	e->k.mouse = 0;
}

static t_env	*init_env(t_scene *scene)
{
	t_env *e;

	e = (t_env*)malloc(sizeof(t_env) * 1);
	ft_init_sdl(e);
	ft_create_win_sdl(e, 0, 0);
	e->rend = ft_init_renderer(e);
	e->scene = scene;
	init_keys(e);
	return (e);
}

int				sdl_env(t_scene *scene)
{
	t_env	*e;

	e = init_env(scene);
	while (1)
	{
		while (SDL_PollEvent(&e->event))
		{
			SDL_GetWindowSize(e->win_sdl, &e->w, &e->h);
			handle_event(e);
			draw(e);
		}
	}
	if (ft_free(e))
		return (1);
	else
		return (0);
}
