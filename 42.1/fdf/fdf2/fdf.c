/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 20:06:46 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/15 21:23:52 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "drawline.h"
#include <mlx.h>


void	init_coord(t_coord *coord, int x, int y)
{
	coord->x = x;
	coord->y = y;
}

/*void	trace_grid(void *mlx_ptr, void *win_ptr)
{
	int		i;
	int		j;
	t_coord	start;
	t_coord	end;

	init_coord(&start, 10, 10);
	init_coord(&end, 10, 200);
	putline(mlx_ptr, win_ptr, start, end);
	init_coord(&start, 10, 200);
	init_coord(&end, 200, 200);
	putline(mlx_ptr, win_ptr, start, end);
	init_coord(&start, 10, 10);
	init_coord(&end, 200, 10);
	putline(mlx_ptr, win_ptr, start, end);
	init_coord(&start, 200, 10);
	init_coord(&end, 200, 200);
	putline(mlx_ptr, win_ptr, start, end);
	//vertical
	i = 0;
	start.y = 220;
	end.y = 240;
		start.x = 440;
		end.x = 420;
	while (i++ < 10)
	{
		j = 0;
		end.x += 200;
		start.x += 200;
		while (j++ <= 10)
		{
			putline(mlx_ptr, win_ptr, start, end);
			start.x -= 20;
			end.x -= 20;
		}
		start.y += 20;
		end.y += 20;
	}
	//horizontal
	i = 0;
	start.x = 620;
	end.x = 640;
	while (i++ < 10)
	{
		j = 0;
		start.y = 220;
		end.y = 220;
		while (j++ <= 10)
		{
			putline(mlx_ptr, win_ptr, start, end);
			start.y += 20;
			end.y += 20;
			end.x -= 20;
			start.x -= 20;
		}
		end.x += 200;
		start.x += 200;
	}
}*/

/*void	trace_grid(void *mlx_ptr, void *win_ptr, int **map)
{
	int i;
	int j;
	t_coord start;
	t_coord end;

	i = 0;
	while (i < 11)
	{
		j = 1;
		while (j < map[i][0])
		{
			init_coord(&start, i * 20, j * 20);
			init_coord(&end, (i + 1) * 20, (j + 0) * 20);
			putline(mlx_ptr, win_ptr, start, end);
			j += 2;
		}
		j = 1;
		while (j < map[i][0])
		{
			init_coord(&start, i * 20, j * 20);
			init_coord(&end, (i + 0) * 20, (j + 1) * 20);
			putline(mlx_ptr, win_ptr, start, end);
			j += 2;
		}
		i += 2;
	}
}*/

void	trace_grid(void *mlx_ptr, void *win_ptr, t_coord **map)
{
	t_coord start;
	t_coord end;

	init_coord(&start, 20, 20);
	init_coord(&end, 30, 40);
	putline(mlx_ptr, win_ptr, start, end);
	start = map[0][0];
	ft_putnbr(start.x);
}

int		max(int *tab)
{
	int	max;
	while (tab++)
		if (*tab > max)
			max = *tab;
	return (max);
}

t_coord	**calculate_grid(int **map)
{
	t_coord	**grid;
	size_t	i;
	//size_t	n;

	grid = malloc(sizeof(t_coord**) * 20);
	i = 1;
	n = max(map[0]);
	while (i < 20)
	{
		grid[i] = malloc(sizeof(t_coord*) * map[i][0]);
		i++;
	}
	return (grid);
}

void	fdf(int **map)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "sandwich");
	mlx_pixel_put(mlx_ptr, win_ptr, 500, map[0][0], 0xFF0000);
	trace_grid(mlx_ptr, win_ptr, calculate_grid(map));
//	trace_grid(mlx_ptr, win_ptr, map);
	sleep(100);
}
