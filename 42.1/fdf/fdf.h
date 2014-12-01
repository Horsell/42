/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 20:01:16 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/28 08:33:39 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

void	fdf(int	**map);
int		*parse_map(char *line);
void	putline(void *mlx_ptr, void *win_ptr, t_coord start, t_coord end);

#endif
