/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 20:06:46 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/01 21:58:22 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <mlx.h>

int		*parse_map(char *line)
{
	size_t	n;
	int		*map;
	char	**str;
	size_t	j;

	n = ft_countwords(line, ' ') + 1;
	map = (int*)malloc(sizeof(int*) * n);
	str = ft_strsplit(line, ' ');
	map[0] = n;
	j = 1;
	while (j < n)
	{
		map[j] = ft_atoi(str[j - 1]);
		j++;
	}
	return (map);
}

void	putline(void *mlx_ptr, void *win_ptr, t_coord start, t_coord end)
{
	int	dx;
	int	dy;
	int	D;
	int	x;
	int	y;

	dx = end.x - start.x;
	dy = end.y - start.y;
	D = 2 * dy - dx;
	if (dx > dy)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, start.x, start.y, 0xFF0000);
		x = start.x + 1;
		y = start.y;
		while (x <= end.x)
		{
			if (D > 0)
			{
				y++;
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
				D = D + (2 * dy - 2 * dx);
			}
			else
			{
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
				D = D + (2 * dy);
			}
			x++;
		}
	}
	else
	{
		mlx_pixel_put(mlx_ptr, win_ptr, start.x, start.y, 0xFF0000);
		x = start.x;
		y = start.y + 1;
		while (y <= end.y)
		{
			if (D > 0)
			{
				x++;
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
				D = D + (2 * dx - 2 * dy);
			}
			else
			{
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
				D = D + (2 * dx);
			}
			y++;
		}
	}
}

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
		}
		end.x += 20;
		start.x += 20;
	}
	i = 0;
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
