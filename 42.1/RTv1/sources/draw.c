/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:13:47 by jpirsch           #+#    #+#             */
/*   Updated: 2015/05/11 21:07:49 by sven             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "libft.h"
#include "rtv1.h"
# define XD RD[i * POS_HEIGHT + j].x
# define YD RD[i * POS_HEIGHT + j].y
# define ZD RD[i * POS_HEIGHT + j].z
# define R RD[i * POS_HEIGHT + j].r
# define G RD[i * POS_HEIGHT + j].g
# define B RD[i * POS_HEIGHT + j].b
# define X0 e->scene->cam.r0.x
# define Y0 e->scene->cam.r0.y
# define Z0 e->scene->cam.r0.z

static int	sphere_dist(t_env *e, int i, int j)
{
	double	dist;
	double	b;
	double	c;
	double	t0;
	double	t1;

	b = 2 * (XD * (X0 - XC) + YD * (Y0 - YC) + ZD * (Z0 - ZC));
	c = (X0 - XC) * (X0 - XC) + (Y0 - YC) * (Y0 - YC) + (Z0 - ZC) * (Z0 - ZC) - SR * SR;
	t0 = (-b + sqrt(b * b + 4 * c)) / 2;
	t1 = (-b - sqrt(b * b + 4 * c)) / 2;
	if (t0 > 0 && t1 > 0)
	{
		if (t0 < t1)
			dist = t0;
		else
			dist = t1;
	}
	else if (t1 > 0)
		dist = t1;
	else if (t0 > 0)
		dist = t0;
//	B = 2 * (Xd * (X0 - Xc) + Yd * (Y0 - Yc) + Zd * (Z0 - Zc))
//	C = (X0 - Xc)^2 + (Y0 - Yc)^2 + (Z0 - Zc)^2 - Sr^2
	return (dist);
}

static int	set_color(t_env *e, int i, int j)
{
	int	dist;

	(void)e;
	dist = sphere_dist(e, i, j);
	if (dist > 0)
	{
	//	R = 1 / dist;
		R = 255;
		G = 1 / dist;
		B = 1 / dist;
	}
	RD[i * POS_HEIGHT + j].r = 19;
	draw_point(e, &RD[i * POS_HEIGHT + j]);
	return (dist);
}

static void	loop(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < POS_HEIGHT)
	{
		j = 0;
		while (j < POS_WIDTH)
		{
			set_ray(e, i, j);
			set_color(e, i, j);
			draw_point(e, &RD[i * POS_HEIGHT + j]);
			j++;
		}
		i++;
	}
	ft_putnbr(RD[100].r);
	ft_putstr("done\n");
}

void		draw(t_env *e)
{
	SDL_SetRenderDrawColor(e->rend, 0, 0, 0, 0);
	SDL_RenderClear(e->rend);
	loop(e);
	SDL_RenderPresent(e->rend);
}
