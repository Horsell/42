/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 01:57:41 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/08 13:32:45 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <netdb.h>
# include <netinet/in.h>
# include <sys/types.h>
# include <sys/socket.h>
# include "libft.h"
# include "get_next_line.h"

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

typedef struct			s_env
{
	struct sockaddr_in	serv_addr;
	int					sockfd;
	char				**env;
	char				**av;
	char				**path;
	int					ac;
	int					pc;
	int					ec;
}						t_env;


t_env			*init_env(int portno);
t_env			*empty_env(void);
int				display_env(t_env *e);
char			*get_env(t_env *e, char *var);
int				ft_unsetenv(t_env *e);
int				ft_setenv(t_env *e);
int				ft_setenv_prog(t_env *e, char *var, char *value);
int				ft_change_env(t_env *e, char *var, char *value);
int				ft_cd(t_env *e);
int				search_env(t_env *e, char *var);
int				ft_exec(t_env *e);
void			ft_execve(char *cmd, char **av, char **env);

#endif
