/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/31 03:03:20 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/01 00:43:20 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putline(int line_size)
{
	int i;

	i = 0;
	while (i < line_size)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar('/');
	while (i < line_size - 2)
	{
		ft_putchar('*');
		i++;
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void	ft_print_door(int door_width, int dollar_line)
{
	int i;
	int dollar_location_x;

	i = 0;
	dollar_location_x = door_width - 1;
	while (i <= door_width)
	{
		if (i == dollar_location_x && dollar_line)
			ft_putchar('$');
		else
			ft_putchar('|');
		i++;
	}
}

void	ft_putline_door(int line_size, int door_height, int dollar_line)
{
	int door_width;
	int door_location_x;
	int i;

	i = 0;
	door_width = door_height;
	door_location_x = (line_size / 2) - (door_width);
	while (i < line_size)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar('/');
	while (i < door_location_x)
	{
		ft_putchar('*');
		i++;
	}
	if (dollar_line == 1)
		ft_print_door(door_width, dollar_line);
	i = 0;
	while (i < line_size - 2)
	{
		ft_putchar('*');
		i++;
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

int		dollar_line(int door_height, int line)
{
	int dollar_location_y;

	dollar_location_y = (door_height / 2) + 1;
	if (dollar_location_y == line)
		return (1);
	else
		return (0);
}

void	ft_sastantua(int size)
{
	int floor_height;
	int door_height;
	int line_size;
	int i;
	int j;
	int s;

	s = 0;
	i = 1;
	line_size = 0;
	door_height = size; //a supprimer apres
	while (i <= size)
	{
		j = 0;
		floor_height = i + 1;
		while (j <= floor_height)
		{
			line_size = ((s / 2) + 3);
			if (i != size)
				ft_putline(line_size);
			else if (i == size && j >= floor_height - door_height)
				ft_putline_door(line_size, size, dollar_line(door_height, j));
			j++;
			s++;
		}
		i++;
	}
}

int		main(void)
{
	ft_sastantua(6);
	return (0);
}
