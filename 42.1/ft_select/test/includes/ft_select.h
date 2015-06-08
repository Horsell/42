/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:24:41 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/04 18:49:16 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# define INVERT_COLOR "so"
# define REINVERT_COLOR "me"
# define UNDERLINE_ON "us"
# define UNDERLINE_ON "us"
# define UNDERLINE_OFF "ue"
# define LEFT "le"
# define UP "up"
# define DOWN "do"
# define RIGHT "ri"
# define DELETE_LINE "dl"
# include <signal.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct	termios t_termios;

typedef struct	s_env
{
	t_termios	term;
	t_list		elems;
}				t_env;

int		ft_putc(int c);
void	initialize_terminal(char **av);
void	restore_term(int success);
#endif
