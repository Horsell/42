/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:36 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/18 05:19:15 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		check_builtin(t_env *e)
{
	int		ret;

	if (!e->av[0])
		return (0);
	ret = (ft_strequ(e->av[0], "env") && !(e->av[1])) ? display_env(e) : 0;
	if (ret != 2)
		ret = (ft_strequ(e->av[0], "cd")) ? ft_cd(e) : 0;
	if (ret != 2)
		ret = (ft_strequ(e->av[0], "setenv")) ? ft_setenv(e) : 0;
	if (ret != 2)
		if (ft_countwords(e->av[0], ' ') > 1)
			ret = (ft_strequ(e->av[0], "unsetenv")) ? ft_unsetenv(e) : 0;
	if (ret != 2)
		ret = (ft_strcmp(e->av[0], "exit")) ? 0 : 1;
	return (ret);
}

t_env	*init_env(char **env)
{
	t_env	*e;
	char	*path;
	int		i;
	t_list	*hash;

	if (!(env))
		return (NULL);
	e = malloc(sizeof(t_env));
	e->env = env;
	path = get_env(e, "PATH");
	e->path = ft_strsplit(path, ':');
	e->pc = ft_countwords(path, ':');
	read_path(e);
	i = 0;
	while (env[i])
		i++;
	e->ec = i;
	return (e);
}

int		cmd_to_env(char *line, t_env *e)
{
	if (line)
	{
		e->ac = ft_countwords(line, ' ');
		line = ft_strtrim(line);
		e->av = ft_strsplit(line, ' ');
		return (1);
	}
	else
		return (0);
}

int		check_cmd(char *line, t_env *e)
{
	int		ret;
	int		i;

	if (cmd_to_env(line, e))
	{
		ret = check_builtin(e);
		(ret == 2) ? 1 : check_path(e);
		return (ret);
	}
	else
	{
		ft_putendl_fd("Error while splitting command", 2);
		return (1);
	}
}
