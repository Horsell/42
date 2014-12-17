/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 07:45:58 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/02 11:05:54 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWLINE_H
# define DRAWLINE_H
# include "fdf.h"

void	putline(void *mlx_ptr, void *win_ptr, t_coord start, t_coord end);
void	aaaa(void *mlx_ptr, void *win_ptr, t_coord start, t_coord end, int dx,\
		int dy);
void	bbbb(void *mlx_ptr, void *win_ptr, t_coord start, t_coord end, int dx,\
		int dy);
void	cccc(void *mlx_ptr, void *win_ptr, t_coord start, t_coord end, int dx,\
		int dy);

#endif
