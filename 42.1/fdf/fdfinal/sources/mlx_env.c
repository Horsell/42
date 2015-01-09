/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 02:15:18 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/09 13:10:09 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "fdf.h"


void	px_to_img(t_env *e, int x, int y) 
{
	e->data[y * e->size_line + x * 4 + 2] = e->r + e->c;
	e->data[y * e->size_line + x * 4 + 1] = e->g;
	e->data[y * e->size_line + x * 4] = e->b;
}

void	string_put(char *s1, char *s2,  char *s3, t_env *e, int y)
{
	char *str;

	str = ft_strnew(60);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	str = ft_strcat(str, s3);
	mlx_string_put(e->mlx, e->win, 1200, y, 0xFFFF00, str);
}

void	print_state(t_env *e)
{
	char	*str;

	string_put("Zoom : ", ft_itoa(e->zoom), "", e, 50);
	(e->proj == 0) ? str = ft_strdup("isometric") : (void)e->proj;
	(e->proj == 1) ? str = ft_strdup("parallel") : (void)e->proj;
	(e->proj == 2) ? str = ft_strdup("conic") : (void)e->proj;
	string_put("Projection : ", str, "", e, 60);
	ft_strdel(&str);
	string_put("Offset X : ", ft_itoa(e->decalx), "", e, 70);
	string_put("Offset Y : ", ft_itoa(e->decaly), "", e, 80);
	str = ft_strnew(20);
	str = ft_strcat(str, " G = ");
	str = ft_strcat(str, ft_itoa((int)e->g));
	str = ft_strcat(str, " B = ");
	str = ft_strcat(str, ft_itoa((int)e->b));
	string_put("Color : R = ", ft_itoa((int)e->r), str, e, 90);
	ft_strdel(&str);
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
	e.cte1 = 0.6;
	e.zoom = 4;
	e.decalx = 50;
	e.decaly = 50;
	e.r = 0;
	e.g = 0;
	e.b = 0;
	init_t_key(&e.key);

	draw_grid(&e);

	mlx_hook(e.win, 2, 1, key_press, &e);
	mlx_hook(e.win, 3, 2, key_release, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
}
