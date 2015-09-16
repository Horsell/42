/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:24:41 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/12 14:28:34 by jpirsch          ###   ########.fr       */
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
# include <termios.h>
# include <term.h>
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
# define START 0
# define WORD 1
# define CMD 2
# define ARG 3
# define FILEE 4
# define SEP 5
# define PIPE 6
# define R_RED 7
# define L_RED 8
# define RR_RED 9
# define LL_RED 10
# define PRESENT e->tokens[j].id_token
# define PRESENT_val e->tokens[j].val
# define LAST e->tokens[j - 1].id_token

typedef struct	s_tok
{
	int	id_token;
	char	*val;
}		t_tok;

typedef struct	s_env
{
	char		**env;
//	t_list		*env_l;
	char		**av;
	char		**path;
	char		*save;
	t_list		**hashtab;
	t_list		*hash;
	t_tok		*tokens;
	int		ac;
	int		pc;
	int		hc;
	int		ec;
}			t_env;

typedef struct	termios t_termios;

t_env			*init_env(char **env);
t_env			*empty_env();
int	parse_cmd(char *line, t_env *e);
int			check_cmd(char *line, t_env *e);
int			display_env(t_env *e);
char			*get_env(t_env *e, char *var);
int			ft_unsetenv(t_env *e);
int			ft_setenv(t_env *e);
int			ft_setenv_prog(t_env *e, char *var, char *value);
int			ft_change_env(t_env *e, char *var, char *value);
int			ft_cd(t_env *e);
int			search_env(t_env *e, char *var);
int			ft_exec(t_env *e);
void			ft_execve(char *cmd, char **av, char **env);
int			check_path(t_env *e, char *line);
int			check_builtin(t_env *e);
t_list			*init_hashtable(t_env *e);
void			read_path(t_env *e, int i, int j);
int			cmd_to_env(char *line, t_env *e);
//	LEXER

int		is_pipe(char *line, int *i);
int		is_l_red(char *line, int *i);
int		is_r_red(char *line, int *i);
int		is_ll_red(char *line, int *i);
int		is_rr_red(char *line, int *i);

int		is_op(char *line, int *i);
int		is_reserved_char(char c);
int		is_word(char *line, int *i);
int		is_cmd(char *line, int *i);
int		ft_build_symbol_table(char *line, t_env *e, int i, int j);

//	PARSER

int	ft_build_exec_tree(t_env *e);

#endif
