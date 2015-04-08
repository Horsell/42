/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:24:41 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/08 07:33:03 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H
# include <signal.h>
# include <sys/wait.h>
# include "libft.h"
# include "get_next_line.h"
# include <dirent.h>
# include <sys/stat.h>
# include "libft.h"
# define C_NONE "\033[0m"
# define C_BOLD "\033[1m"
# define C_BLACK "\033[30m"
# define C_RED "\033[31m"
# define C_GREEN "\033[32m"
# define C_BROWN "\033[33m"
# define C_BLUE "\033[0;34m"
# define C_MAGENTA "\033[35m"
# define C_CYAN "\033[36m"
# define C_GRAY "\033[37m"

typedef struct	s_env
{
	char		**env;
	char		**av;
	char		**path;
	t_list		*hash;
	int			ac;
	int			pc;
	int			ec;
}				t_env;

t_env	*init_env(char **env);
int		check_cmd(char *line, t_env *e);
void	display_env(t_env *e);
char	*get_env(t_env *e, char *var);
void	ft_unsetenv(t_env *e);
void	ft_setenv(t_env *e);
int		search_env(t_env *e, char *var);
void	ft_execve(char *cmd, char **av, char **env);
int		check_path(t_env *e);
int		check_builtin(t_env *e);

int		cmd_to_env(char *line, t_env *e);
#endif
