/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/25 08:26:11 by sven             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_sh1.h"


void	display_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

int		search_env(char **env, char *var)
{
	int i;

	i = 1;
	while (env[i] != NULL)
	{
		if (!(ft_strncmp(env[i], var, ft_strlen(var) - 1)))
			return (i);
		i++;
	}
	return (0);
}

void	prompt(char **env)
{
	int i;

	i = 0;
	if (env == NULL)
		ft_putstr(" >");
	else
	{
		i = search_env(env, "USER");
		ft_putstr(C_RED);
		ft_putstr(&env[i][ft_strlen("USER") + 1]);
		ft_putstr(C_BLUE);
		ft_putstr("@");
		ft_putstr(C_BROWN);
		i = search_env(env, "PWD");
		ft_putstr(&env[i][ft_strlen("PWD") + 1]);
		ft_putstr(C_NONE);
		ft_putstr("/>");
	}
}

void	ft_execve(char *cmd, char **av, char **env)
{
	pid_t	father;

	if (cmd != NULL)
	{
		father = fork();
		if (father > 0)
			wait(NULL);
		if (father == 0)
		{
			execve(cmd, av, env);
			exit(EXIT_FAILURE);
		}
	}
}

int		check_path(char **env, char **av, char *bin)
{
	int		i;
	char	*path;
	char	**tab_path;
	char	*join;

	i = search_env(env, "PATH");
	path = &env[i][ft_strlen("PATH") + 1];
	tab_path = ft_strsplit(path, ':');
	i = 1;
	while (tab_path[i])
	{
		join = ft_strjoin(tab_path[i], "/");
		join = ft_strjoin(join, bin);
		ft_execve(join, av, env);
		i++;
	}
	return (--i);
}

int		check_builtin(char *line, char **env)
{
	int		ret;

	ret = 1;
	ret = (ft_strcmp(line, "exit")) ? 0 : 1;
	(ft_strcmp(line, "env")) ? 1 : display_env(env);
	return (ret);
}

int		check_command(char *line, char **av, char **env)
{
	int ret;

	ret = check_builtin(line, env);
	check_path(env, av, line);
		//	ft_putstr("Command not found");
	return (ret);
}

int		main(int ac, char **av, char **env)
{
	char	*line;
	int		ret;

	ret = 0;
	while (ret == 0)
	{
			prompt(env);
		if (get_next_line(0, &line))
		{
			ret = check_command(line, av, env);
			if (ret == 1)
				break;
		}
	}
	return (0);
}
