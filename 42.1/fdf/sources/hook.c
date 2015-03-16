/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 12:17:52 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/11 21:52:16 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "fdf.h"

void	init_t_key(t_key *key)
{
	key->echap = 0;
	key->decal_down = 0;
	key->decal_up = 0;
	key->decal_right = 0;
	key->decal_left = 0;
	key->zoom = 0;
	key->zoom_back = 0;
	key->cte1_increase = 0;
	key->cte1_decrease = 0;
	key->isometric = 0;
	key->parallel = 0;
	key->conic = 0;
	key->scale_increase = 0;
	key->scale_decrease = 0;
	key->r = 0;
	key->g = 0;
	key->b = 0;
}

int		key_press(int keycode, t_env *e)
{
	ft_putnbr(keycode);
	(keycode == 53) ? e->key.echap = 1 : (void)keycode;
	(keycode == 125) ? e->key.decal_down = 1 : (void)keycode;
	(keycode == 126) ? e->key.decal_up = 1 : (void)keycode;
	(keycode == 124) ? e->key.decal_right = 1 : (void)keycode;
	(keycode == 123) ? e->key.decal_left = 1 : (void)keycode;
	(keycode == 65451) ? e->key.zoom = 1 : (void)keycode;
	(keycode == 65453) ? e->key.zoom_back = 1 : (void)keycode;
	(keycode == 61) ? e->key.scale_increase = 1 : (void)keycode;
	(keycode == 45) ? e->key.scale_decrease = 1 : (void)keycode;
	(keycode == 108) ? e->key.cte1_increase = 1 : (void)keycode;
	(keycode == 107) ? e->key.cte1_decrease = 1 : (void)keycode;
	(keycode == 105) ? e->key.isometric = 1 : (void)keycode;
	(keycode == 112) ? e->key.parallel = 1 : (void)keycode;
	(keycode == 99) ? e->key.conic = 1 : (void)keycode;
	(keycode == 114) ? e->key.r = 1 : (void)keycode;
	(keycode == 103) ? e->key.g = 1 : (void)keycode;
	(keycode == 98) ? e->key.b = 1 : (void)keycode;
	return (1);
}

int		key_release(int keycode, t_env *e)
{
	(keycode == 53) ? e->key.echap = 0 : (void)keycode;
	(keycode == 125) ? e->key.decal_down = 0 : (void)keycode;
	(keycode == 126) ? e->key.decal_up = 0 : (void)keycode;
	(keycode == 124) ? e->key.decal_right = 0 : (void)keycode;
	(keycode == 123) ? e->key.decal_left = 0 : (void)keycode;
	(keycode == 65451) ? e->key.zoom = 0 : (void)keycode;
	(keycode == 65453) ? e->key.zoom_back = 0 : (void)keycode;
	(keycode == 61) ? e->key.scale_increase = 0 : (void)keycode;
	(keycode == 45) ? e->key.scale_decrease = 0 : (void)keycode;
	(keycode == 108) ? e->key.cte1_increase = 0 : (void)keycode;
	(keycode == 107) ? e->key.cte1_decrease = 0 : (void)keycode;
	(keycode == 105) ? e->key.isometric = 0 : (void)keycode;
	(keycode == 112) ? e->key.parallel = 0 : (void)keycode;
	(keycode == 99) ? e->key.conic = 0 : (void)keycode;
	(keycode == 114) ? e->key.r = 0 : (void)keycode;
	(keycode == 103) ? e->key.g = 0 : (void)keycode;
	(keycode == 98) ? e->key.b = 0 : (void)keycode;
	return (1);
}

int		loop_hook(t_env *e)
{
	(e->key.echap == 1) ? exit(0) : (void)e->key.echap;
	(e->key.decal_down == 1) ? e->decaly -= e->zoom / 2 : (void)e->key.echap;
	(e->key.decal_up == 1) ? e->decaly += e->zoom / 2 : (void)e->key.echap;
	(e->key.decal_right == 1) ? e->decalx -= e->zoom / 2 : (void)e->key.echap;
	(e->key.decal_left == 1) ? e->decalx += e->zoom / 2 : (void)e->key.echap;
	(e->key.zoom == 1) ? e->zoom += 4 : (void)e->key.echap;
	(e->key.zoom_back == 1) ? e->zoom -= 4 : (void)e->key.echap;
	(e->key.scale_increase == 1) ? e->scale += 0.2 : (void)e->key.echap;
	(e->key.scale_decrease == 1) ? e->scale -= 0.2 : (void)e->key.echap;
	(e->key.cte1_increase == 1) ? e->cte1 += 0.01 : (void)e->key.echap;
	(e->key.cte1_decrease == 1) ? e->cte1 -= 0.01 : (void)e->key.echap;
	(e->key.isometric == 1) ? e->proj = 0 : (void)e->key.echap;
	(e->key.parallel == 1) ? e->proj = 1 : (void)e->key.echap;
	(e->key.conic == 1) ? e->proj = 2 : (void)e->key.echap;
	(e->key.r == 1) ? e->r += 20 : (void)e->key.echap;
	(e->key.g == 1) ? e->g += 20 : (void)e->key.echap;
	(e->key.b == 1) ? e->b += 20 : (void)e->key.echap;
	ft_bzero(e->data, e->size_line * 900);
	draw_grid(e);
	return (1);
}
