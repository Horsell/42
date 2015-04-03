/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:24:41 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/03 16:59:09 by jpirsch          ###   ########.fr       */
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
#define C_NONE "\033[0m"
#define C_BOLD "\033[1m"
#define C_BLACK "\033[30m"
#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_BROWN "\033[33m"
#define C_BLUE "\033[0;34m"
#define C_MAGENTA "\033[35m"
#define C_CYAN "\033[36m"
#define C_GRAY "\033[37m"

void	display_env(char **env);
int		search_env(char **env, char *var);
void	ft_execve(char *cmd, char **av, char **env);
int		check_path(char **env, char **av, char *bin);
int		check_builtin(char *line, char **env);
int		check_command(char *line, char **av, char **env);

#endif
