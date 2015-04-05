/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:36 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/04 22:36:56 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_sh1.h"

int		check_builtin(t_env *e)
{
	int		ret;

	ret = 1;
	ret = (ft_strcmp(e->av[0], "exit")) ? 0 : 1;
	(ft_strequ(e->av[0], "env")) ? display_env(e) : 2;
	if (ft_countwords(e->av[0], ' ') > 1)
		(ft_strequ(e->av[0], "unsetenv")) ? ft_unsetenv(e) : 2;
	return (ret);
}

t_env	*init_env(char **env)
{
	t_env	*e;
	char	*path;

	e = malloc(sizeof(t_env *));
	e->env = env;
	path = e->env[search_env(e, "PATH")] + 5;
	e->path = ft_strsplit(path, ':');
	e->path[0] = ft_strsub(path, 0, 5);//ft_strchr_len(path, ':'));
//	ft_putstr(e->path[0]);
	return (e);
}

int		cmd_to_env(char *line, t_env *e)
{
	if (line)
	{
		e->ac = ft_countwords(line, ' ') - 1;
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
		ft_putstr("debug");
//		ft_putstr(e->path[0]);
		ret = check_builtin(e);
		(ret == 1) ? check_path(e) : 1;
		return (ret);
	}
	else
		return (1);
}
