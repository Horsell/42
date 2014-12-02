/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 20:06:46 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/02 09:23:24 by jpirsch          ###   ########.fr       */
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

void	trace_grid(void *mlx_ptr, void *win_ptr)
{
	int		i;
	int		j;
	t_coord	start;
	t_coord	end;

	i = 0;
	j = 0;
	/*init_coord(&start, 20, 20);
	init_coord(&end, 200, 100);
	putline(mlx_ptr, win_ptr, start, end);
	init_c+oord(&start, 20, 20);
	init_coord(&end, 100, 200);
	putline(mlx_ptr, win_ptr, start, end);
	while (end.x < 200)
	{
		init_coord(&end, end.x + 1, end.y - 1); 
		putline(mlx_ptr, win_ptr, start, end);
	}
	i = 220;
	while (i < 420)
	{
		j = 220;
		while (j < 420)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFF0000);
			j++;
		}
		i++;
	}*/
	/*init_coord(&start, 10, 10);
	init_coord(&end, 100, 200);
	putline(mlx_ptr, win_ptr, start, end);
	init_coord(&start, 10, 10);
	init_coord(&end, 200, 100);
	putline(mlx_ptr, win_ptr, start, end);
	end.x = 100;
	while (end.x < 200)
	{
		end.y = 100;
		while (end.y < 200)
		{
			putline(mlx_ptr, win_ptr, start, end);
			end.y++;	
		}
		end.x++;	
	}*/

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
	i = 0;
	start.x = 440;
	end.x = 440;
	while (i++ <= 10)
	{
		j = 0;
		start.y = 220;
		end.y = 240;
		while (j++ < 10)
		{
			putline(mlx_ptr, win_ptr, start, end);
			start.y += 20;
			end.y += 20;
			end.x -= 20;
			end.y -= 20;
		}
		end.x += 200;
		start.x += 200;
	}
	/*i = 0;
	start.x = 200;
	end.x = 220;
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
		}
		end.x += 20;
		start.x += 20;
	}*/



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
}

int		max(int *tab)
{
	int	max;
	while (tab++)
		if (*tab > max)
			max = *tab;
	return (max);
}

/*t_coord	**calculate_grid(int **map)
{
	t_coord	**grid;
	size_t	i;
	size_t	n;

	grid = malloc(sizeof(t_coord**) * 20);
	i = 0;
	n = max(map[0]);
	while (i < 20)
	{
		grid[i] = malloc(sizeof(t_coord*) * n);
		i++;
	}
	return (grid);
}*/

void	fdf(int **map)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "sandwich");
	mlx_pixel_put(mlx_ptr, win_ptr, 500, map[0][0], 0xFF0000);
	//trace_grid(mlx_ptr, win_ptr, calculate_grid(map));
	trace_grid(mlx_ptr, win_ptr);
	sleep(100);
}
