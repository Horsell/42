/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 18:46:16 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/08 19:55:06 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef	FT_POINT_H
# define FT_POINT_H
typedef	struct	s_point
{
	int x;
	int y;
}				t_point;
void			set_point(t_point *point);
#endif
