/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:24:41 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/09 19:07:24 by jpirsch          ###   ########.fr       */
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

typedef struct			s_clist
{
	char				*underlined;
	char				*selected;
	char				*arg;
	int					isfirst;
	struct s_clist		*prev;
	struct s_clist		*next;
}						t_clist;

typedef struct			s_env
{
	t_termios			term;
	t_clist				*clist;
	t_winsize			*win;
	int					col;
	int					line;
	int					nbargs;
}						t_env;

t_clist					*ft_clstnew(char *arg, int isfirst);
void					ft_clstadd(t_clist **last, t_clist **first, t_clist *new);
void					ft_clstdel(t_clist *alst);
int						ft_putc(int c);
void					signals();
void					up(t_env *e);
void					down(t_env *e);
t_env					*init_select(int ac, char **av);
void					initialize_terminal();
t_clist					*init_arglist(int ac, char **av);
void					display_args(t_clist *clist);
void					restore_term(int success);
void					close_select(t_env *e);
#endif
