/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 02:15:18 by jpirsch           #+#    #+#             */
/*   Updated: 2015/02/10 10:56:06 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	ft_putnbr(keycode);
	(keycode == 65307) ? exit(0) : (void)keycode;
	(keycode == 65362) ? e->decaly -= 0.2 : (void)keycode;
	(keycode == 65364) ? e->decaly += 0.2 : (void)keycode;
	(keycode == 65361) ? e->decalx -= 0.2 : (void)keycode;
	(keycode == 65363) ? e->decalx += 0.2 : (void)keycode;
	(keycode == 65451) ? e->zoom *= 2 : (void)keycode;
	(keycode == 65453) ? e->zoom /= 2 : (void)keycode;
	(keycode == 120) ? e->x += 0.2 : (void)keycode;
	(keycode == 121) ? e->y += 0.2 : (void)keycode;
	(keycode == 116) ? e->y -= 0.2 : (void)keycode;
	(keycode == 122) ? e->x -= 0.2 : (void)keycode;
	(keycode == 114) ? e->R += 20 : (void)keycode;
	(keycode == 103) ? e->G += 20 : (void)keycode;
	(keycode == 98) ? e->B += 20 : (void)keycode;
	draw(e);
	return (1);
}

void	print_state(t_env *e)
{
	char	*str;

	/*str = ft_strdup("Zoom : ");
	str = ft_strcat(str, ft_itoa(e->zoom));
	mlx_string_put(e->mlx, e->win, 1200, 50, 0xFFFF00, str);
	ft_bzero(str, ft_strlen(str));*/
	str = ft_strdup("Offset X : ");
	str = ft_strcat(str, ft_itoa(e->decalx));
	mlx_string_put(e->mlx, e->win, 1200, 70, 0xFFFF00, str);
	ft_bzero(str, ft_strlen(str));
	str = ft_strcat(str, "Offset Y : ");
	str = ft_strcat(str, ft_itoa(e->decaly));
	mlx_string_put(e->mlx, e->win, 1200, 80, 0xFFFF00, str);
	ft_bzero(str, ft_strlen(str));
	str = ft_strcat(str, "Color : ");
	str = ft_strcat(str, ft_itoa((int)e->R));
	str = ft_strcat(str, ft_itoa((int)e->G));
	str = ft_strcat(str, ft_itoa((int)e->B));
	mlx_string_put(e->mlx, e->win, 1200, 90, 0xFFFF00, str);
}

void	px_to_img(t_env *e, int x, int y) 
{
	e->data[y * e->size_line + x * 4 + 2] = e->R;
	e->data[y * e->size_line + x * 4 + 1] = e->G;
	e->data[y * e->size_line + x * 4] = e->B;
}

void	env(int fract_type)
{
	t_env	e;

	e.fract_type = fract_type;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1440, 900, "sandwich");
	e.img = mlx_new_image(e.mlx, 1440, 900);
	e.data = mlx_get_data_addr(e.img, &e.depth, &e.size_line, &e.endian);
	e.zoom = 0.8;
	e.x = 0.0;
	e.y = 0.0;
	e.decalx = 2.5;
	e.decaly = 1;
	e.R = 240;
	e.G = 0;
	e.B = 0;
		ft_putnbr(e.fract_type);

	draw(&e);

	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_loop(e.mlx);
}
