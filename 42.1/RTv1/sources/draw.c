/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:13:47 by jpirsch           #+#    #+#             */
/*   Updated: 2015/05/03 12:45:29 by sven             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "libft.h"
#include "rtv1.h"

static int	sphere_dist(t_env *e)
{
	int	dist;
	return (dist);
}

static int	get_d(t_env *e)
{
	int	dist;

	(void)e;
	dist = sphere_dist(e);
	return (dist);
}

static void	loop(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < e->w)
	{
		j = 0;
		while (j < e->h)
		{
			get_d(e);
			j++;
		}
		i++;
	}
}

void		draw(t_env *e)
{
	SDL_SetRenderDrawColor(e->rend, 0, 0, 0, 0);
	SDL_RenderClear(e->rend);
	loop(e);
	SDL_RenderPresent(e->rend);
}
