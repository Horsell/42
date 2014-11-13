/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 17:01:16 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/12 17:01:20 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H

typedef ft_bool int;

typedef	struct	s_door
{
	int		state;	
}				t_door

# define TRUE 1
# define OPEN 1
# define CLOSE 0

#endif
