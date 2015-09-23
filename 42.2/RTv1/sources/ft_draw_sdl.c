/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 11:44:32 by jpirsch           #+#    #+#             */
/*   Updated: 2015/05/09 20:40:30 by sven             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rtv1.h"

void	draw_point(t_env *e, t_point *pt)
{
	SDL_SetRenderDrawColor(e->rend, pt->r, pt->g, pt->b,
			255);
	if (SDL_RenderDrawPoint(e->rend, pt->x, pt->y) < 0)
	{
		ft_putstr_fd("SetRenderDrawPoint error ", 2);
		ft_putendl_fd((char*)SDL_GetError(), 2);
		ft_free(e);
		exit(-1);
	}
}
