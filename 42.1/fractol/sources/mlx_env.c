/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 02:15:18 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/16 04:18:31 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fractol.h"

int		key_hook(int keycode, t_env *e)
{
	ft_putnbr(keycode);
	(keycode == 53) ? exit(0) : 1;
	(keycode == 125) ? e->decaly -= 0.2 : 1;
	(keycode == 126) ? e->decaly += 0.2 : 1;
	(keycode == 124) ? e->decalx -= 0.2 : 1;
	(keycode == 123) ? e->decalx += 0.2 : 1;
	(keycode == 34) ? e->max_iter *= 2 : 1;
	(keycode == 0) ? e->x += 0.2 : 1;
	(keycode == 2) ? e->y += 0.2 : 1;
	(keycode == 3) ? e->y -= 0.2 : 1;
	(keycode == 1) ? e->x -= 0.2 : 1;
	(keycode == 15) ? e->h += 0.1 : 1;
	(keycode == 5) ? e->v += 0.1 : 1;
	(e->h > 1) ? e->h = 0 : 1;
	(e->v > 1) ? e->v = 0 : 1;
	(keycode == 11) ? e->b += 20 : 1;
	(keycode == 38) ? e->fract_type = 0 : 1;
	(keycode == 46) ? e->fract_type = 1 : 1;
	(keycode == 17) ? e->fract_type = 2 : 1;
	if (keycode == 35)
		e->pause = (e->pause == 0) ? 1 : 0;
	draw(e);
	mlx_do_sync(e->mlx);
	return (1);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		e->zoom *= 1.2;
		e->decalx += ((x / 1440) - (x / (1440 * 2)) * e->zoom) - e->decalx;
		e->decaly += ((y / 900) - (x / (1440 * 2)) * e->zoom) - e->decaly;
	}
	if (button == 5)
	{
		e->zoom /= 1.2;
//		e->decaly += ((y / 900) * e->zoom);
//		e->decalx += ((x / 1440) * e->zoom);
		e->decalx += (((x / 1440) - (x / (1440 * 2))) * e->zoom);// - e->decalx;
		e->decaly += (((y / 900) - (y / (900 * 2))) * e->zoom); //- e->decaly;
		//e->decalx *= (x / 1440) * 3;
		//e->decaly *= (y / 900) * 2;
	}
	(void)x;
	(void)y;
	draw(e);
	mlx_do_sync(e->mlx);
	return (1);
}

void	px_to_img(t_env *e, int x, int y)
{
	e->data[y * e->size_line + x * 4 + 2] = e->r;
	e->data[y * e->size_line + x * 4 + 1] = e->g;
	e->data[y * e->size_line + x * 4] = e->b;
}

int		mouse_motion(int x, int y, t_env *e)
{
	if (e->pause == 0)
	{
		e->x = ((double)x / 1440) * 3.5 - 2.5;
		e->y = ((double)y / 900) * 2 - 1;
		draw(e);
		mlx_do_sync(e->mlx);
	}
	return (1);
}

void	env(int fract)
{
	t_env	e;

	e.fract_type = fract;
	if (!(e.mlx = mlx_init()))
		return ;
	if (!(e.win = mlx_new_window(e.mlx, 1440, 900, "fractol")))
		return ;
	if (!(e.img = mlx_new_image(e.mlx, 1440, 900)))
		return ;
	if (!(e.data = mlx_get_data_addr(e.img, &e.depth, &e.size_line, &e.endian)))
		return ;
	e.max_iter = 100;
	e.zoom = 2.0;
	e.x = 0.0;
	e.y = 0.0;
	e.decalx = 2.5;
	e.decaly = 1;
	e.r = 240;
	e.g = 0;
	e.b = 0;
	draw(&e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_hook(e.win, 6, (1 << 6), &mouse_motion, &e);
	mlx_loop(e.mlx);
}
