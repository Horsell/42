/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:59:59 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/15 15:01:28 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 6

typedef struct	s_info
{
	int			i;
	int			status;
	int			ret;
	char		*s;
}				t_info;

int				get_next_line(int fd, char **line);
void			ft_putnbr(int n);

#endif
