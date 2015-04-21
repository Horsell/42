/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:36 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/21 17:27:33 by jpirsch          ###   ########.fr       */
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
	t_list	*new;

	e = malloc(sizeof(t_env));
	e->env = env;
	path = get_env(e, "PATH");
	e->path = ft_strsplit(path, ':');
	e->pc = ft_countwords(path, ':');
	read_path(e);
	e->env_l = ft_lstnew(env[0], sizeof(char) * ft_strlen(env[0]));
	i = 1;
	while (env[i])
	{
		new = ft_lstnew(env[i], sizeof(char) * ft_strlen(env[0]));
		ft_lstadd(&e->env_l, new);
		ft_putendl(env[i]);
		i++;
	}
	new = e->env_l;
	while (new->next)
	{
	ft_putendl("debug");
		ft_putendl(*(char**)new->content);
		new = new->next;
	}
	e->ec = i;
	return (e);
}

int		cmd_to_env(char *line, t_env *e)
{
	if (line && line[0])
	{
		line = ft_strtrim(line);
		e->ac = ft_countwords(line, ' ');
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
		(ret == 2 || ret == 1) ? 1 : check_path(e);
		return (ret);
	}
	else
	{
//		ft_putendl_fd("Error while splitting command", 2);
		return (0);//1 pour exit
	}
}
