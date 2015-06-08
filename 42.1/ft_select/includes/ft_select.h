/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:24:41 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/08 08:47:04 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
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
typedef struct	winsize t_winsize;

typedef struct	s_env
{
	t_termios	term;
	t_list		*list;
	t_winsize	*win;
	int			col;
	int			lines;
	int			nbargs;
}				t_env;

typedef struct	s_clist
{
	char		*underline;
	char		*selected;
	t_clist		*prev;
	t_clist		*next;
}				t_clist;

int		ft_putc(int c);
void	initialize_terminal(char **av);
void	restore_term(int success);
#endif
