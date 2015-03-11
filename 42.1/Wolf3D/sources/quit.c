/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 00:39:31 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/10 00:42:15 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf.h"

void	ft_quit(t_env *e)
{
	int i;

	i = 0;
	while (i < e->map[0][0])
	{
		free(e->map[i]);
		i++;
	}
	if (e->texture)
		SDL_DestroyTexture(e->texture);
	if (e->pSprite)
		SDL_FreeSurface(e->pSprite);
	if (e->rend)
		SDL_DestroyRenderer(e->rend);
	if (e->win_sdl)
		SDL_DestroyWindow(e->win_sdl);
	SDL_Quit();
}
