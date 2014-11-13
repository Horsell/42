/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/31 03:03:20 by jpirsch           #+#    #+#             */
/*   Updated: 2014/08/31 10:55:36 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putline(int line_size)
{
	ft_putchar('/');
	while (i < line_size - 2)
	{
		ft_putchar('*');
	}
	ft_putchar('\');
}

void ft_putline_door(int line_size, int door_height, int door_width)
{
	int door_location_x;
	int dollar_location_x;
	int dollar_location_y;

	ft_putchar('/');
	while (i < door_location_x)
	{
		ft_putchar('*');
		i++;
	}
	i = 0;
	while (i < door_width)
	{
		if (i = dollar_location_y)
		{
			ft_putchar('$');
		}
		else
		{
			ft_putchar('|');
		}
		i++;
	}
	while (i < line_size - 2)
	{
		ft_putchar('*');
		i++;
	}
	ft_putchar('\');
}

/*	Links between var acronym and its meaning
 *	sh = floor height
 *	dh = door height
 *	sl = size line
 */	

void	ft_sastantua(int size)
{
	int floor_height;
	int door_height;
	int door_width;
	int line_size;
	int dollar_location;
	int i;
	int j;

	i = 1;
	j = 0;
	line_size = 0;
	door_height = (size / 2) * 2 + 1;
	while (i <= size)
	{
		while (j < )
		{
			line_size = j + 2;2; 
			ft_putline(line_size);
			j++;
		}
		floor_height = i + 2;
		i++;
	}

}

int		main(void)
{
	ft_sastantua(5);
	return (0);
}
