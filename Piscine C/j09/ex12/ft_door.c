/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 17:00:57 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/12 17:01:05 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_door.h"

void		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

ft_bool		close_door(t_door *door)
{
	ft_putstr("Door closing...");
	t_door->state = CLOSE;
	return (TRUE);
}

ft_bool		is_door_open(t_door *door)
{
	ft_putstr("Door is open ?");
	t_door->state = OPEN;
	return (OPEN);
}

ft_bool 	is_door_close(t_door *door)
{
	ft_putstr("Door is close ?");
	t_door->state = CLOSE;
	return (CLOSE);
}
