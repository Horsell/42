/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 02:15:18 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/03 03:29:07 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	ft_putnbr(keycode);
	(keycode == 65307) ? exit(0) : (void)keycode;
	(keycode == 65362) ? e->decaly -= e->zoom / 2 : (void)keycode;
	(keycode == 65364) ? e->decaly += e->zoom / 2 : (void)keycode;
	(keycode == 65361) ? e->decalx -= e->zoom / 2 : (void)keycode;
	(keycode == 65363) ? e->decalx += e->zoom / 2 : (void)keycode;
	(keycode == 65451) ? e->zoom += 4 : (void)keycode;
	(keycode == 65453) ? e->zoom -= 4 : (void)keycode;
	(keycode == 61) ? e->scale += 0.2 : (void)keycode;
	(keycode == 45) ? e->scale -= 0.2 : (void)keycode;
	(keycode == 105) ? e->proj = 0 : (void)keycode;
	(keycode == 112) ? e->proj = 1 : (void)keycode;
	(keycode == 99) ? e->proj = 2 : (void)keycode;
	(keycode == 114) ? e->R += 20 : (void)keycode;
	(keycode == 103) ? e->G += 20 : (void)keycode;
	(keycode == 98) ? e->B += 20 : (void)keycode;
	draw_grid(e);
	return (1);
}

void	px_to_img(t_env *e, int x, int y) 
{
	e->data[y * e->size_line + x * 4 + 2] = e->R;
	e->data[y * e->size_line + x * 4 + 1] = e->G;
	e->data[y * e->size_line + x * 4] = e->B;
}

void	print_state(t_env *e)
{
	char	*str;

	str = ft_strdup("Zoom : ");
	str = ft_strcat(str, ft_itoa(e->zoom));
	mlx_string_put(e->mlx, e->win, 1200, 50, 0xFFFF00, str);
	str = ft_bzero(str, 9);
	str = ft_strcat(str, "Projection ");
	(e->proj == 0) ? str = ft_strcat(str, "isometric") : (void)e->proj;
	(e->proj == 1) ? str = ft_strcat(str, "parallel") : (void)e->proj;
	(e->proj == 2) ? str = ft_strcat(str, "conic") : (void)e->proj;
	mlx_string_put(e->mlx, e->win, 1200, 60, 0xFFFF00, str);
	str = ft_bzero(str, ft_strlen(str));
	str = ft_strcat(str, "Offset X : ");
	str = ft_strcat(str, ft_itoa(e->decalx));
	mlx_string_put(e->mlx, e->win, 1200, 70, 0xFFFF00, str);
	str = ft_bzero(str, ft_strlen(str));
	str = ft_strcat(str, "Offset Y : ");
	str = ft_strcat(str, ft_itoa(e->decaly));
	mlx_string_put(e->mlx, e->win, 1200, 80, 0xFFFF00, str);
	str = ft_bzero(str, ft_strlen(str));
	str = ft_strcat(str, "Color : ");
	str = ft_strcat(str, ft_itoa((int)e->R));
	str = ft_strcat(str, ft_itoa((int)e->G));
	str = ft_strcat(str, ft_itoa((int)e->B));
	mlx_string_put(e->mlx, e->win, 1200, 90, 0xFFFF00, str);
}

void	env(int **map)
{
	t_env	e;

	e.map = map;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1440, 900, "sandwich");
	e.img = mlx_new_image(e.mlx, 1440, 900);
	e.data = mlx_get_data_addr(e.img, &e.depth, &e.size_line, &e.endian);
	e.proj = 0;
	e.scale = 2.5;
	e.zoom = 4;
	e.decalx = 50;
	e.decaly = 50;
	e.R = 0;
	e.G = 0;
	e.B = 0;

	draw_grid(&e);

	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
