/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 20:55:01 by jpirsch           #+#    #+#             */
/*   Updated: 2014/11/20 08:14:02 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
# define BUF_SIZE 200

typedef struct		s_gnl
{
	char			**tab;
	size_t			index;
	size_t			imax;
}					t_gnl;

int	get_next_line(const int fd, char **line);
#endif
