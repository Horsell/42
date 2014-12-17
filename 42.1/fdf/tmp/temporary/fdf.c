/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2014/12/16 10:06:02 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/17 02:11:07 by jpirsch          ###   ########.fr       */
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
	coord->z = 0;
}

t_coord	**map_to_coord(int **map)
{
	t_coord	**grid;
	int		i;
	int		j;

	grid = malloc(sizeof(t_coord**) * map[1][0]);
	i = 0;
	grid[0][0].y = map[0][0];
	while (i < grid[0][0].y)
	{
		j = 0;
		grid[i] = malloc(sizeof(t_coord*) * map[i + 1][0]);
		while (j < map[i + 1][0])
		{
			if (j == 0)
				grid[i][0].z = map[i + 1][0];
			else
			{
				init_coord(&grid[i][j], (j - 1) * 10, i * 10);
				grid[i][j].z = map[i + 1][j];
			}
			j++;
		}
		i++;
	}
	return (grid);
}

t_coord	**proj(t_coord **grid)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 1;
		while (j < grid[i][0].z)
		{
			grid[i][j].x += 0.5 * grid[i][j].z;
			grid[i][j].y += 0.25 * grid[i][j].z;
			j++;
		}
		i++;
	}
	return (grid);
}

void	trace_grid(void *mlx_ptr, void *win_ptr, int **map)
{
	t_coord start;
	t_coord end;
	t_coord	**grid;
	int		i;
	int		j;

	grid = map_to_coord(map);
	//grid = proj(grid);
	i = 0;
	while (i < grid[0][0].y)
	{
		j = 1;
		while (j < grid[i][0].z)
		{
		start = grid[i][j];
		end = grid[i][j + 1];
			putline(mlx_ptr, win_ptr, start, end);
			j++;
		}
		i++;
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

void	fdf(int **map)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "sandwich");
	mlx_pixel_put(mlx_ptr, win_ptr, 500, map[0][0], 0xff0000);
	trace_grid(mlx_ptr, win_ptr, map);
	sleep(100);
}
