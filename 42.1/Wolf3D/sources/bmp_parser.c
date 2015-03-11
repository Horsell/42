/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 01:11:40 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/11 16:09:15 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf.h"

void	load_image(t_env *e)
{
	e->pSprite = SDL_LoadBMP("textures/Dgiqj.bmp");
	if ( e->pSprite )
	{
		e->texture = SDL_CreateTextureFromSurface(e->rend, e->pSprite);
	}
	else
		fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
}

void	put_sprite(t_env *e)
{
	if (e->texture)
	{
		SDL_Rect dest = { (e->w - (e->pSprite->w + e->w) / 8) / 2, e->h - 
			(e->pSprite->h + e->h) / 8, (e->pSprite->w + e->w)/ 8, 
				(e->pSprite->h + e->h) / 8};
		SDL_RenderCopy(e->rend, e->texture, NULL, &dest);
	}
	else
		fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
}

void	ft_putnbr_hex(char c)
{
	if (c << 6 < 10)
		ft_putchar((c << 6) + 48);
/*	if (c == 10)
		ft_putchar('A');
	if (c == 11)
		ft_putchar('B');
	if (c == 12)
		ft_putchar('C');
	if (c == 13)
		ft_putchar('D');
	if (c == 14)
		ft_putchar('E');
	if (c == 15)
		ft_putchar('F');*/
}

void	bmp(int fd)
{
	char	buf[100001];
	int		i;
	int		ret;

	i = 0;
	ret = read(fd, buf, 100000);
	while (i < ret)
	{
		ft_putnbr_hex(buf[i]);
		i++;
	}
}
