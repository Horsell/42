/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:32:51 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/21 18:56:25 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

t_env	*empty_env()
{
	t_env 	*e;
	char	buf[256];

	ft_putendl_fd("Warning : empty environment.", 2);
	exit(1);
/*	if (!(getcwd(buf, 256)))
	{
			ft_putendl_fd("Error : failed to load current directory", 2);
			exit(1);
	}
	e = malloc(sizeof(t_env));
	e->env = ft_tabmalloc(3, 256);
	ft_strcpy(e->env[0], "PWD="); 
	ft_strcpy(e->env[0] + 4, buf); 
	ft_strcpy(e->env[2], "USER=unknown");*/
	return (e);
}

t_env	*init_env(char **env)
{
	t_env	*e;
	char	*path;
	int		i;
	t_list	*new;

	e = malloc(sizeof(t_env));
	e->env = env;
	e->env[search_env(e, "SHLVL")][6]++;
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

int		search_env(t_env *e, char *var)
{
	int i;

	i = 0;
	while (e->env[i] != NULL)
	{
		if (!(ft_strncmp(e->env[i], var, ft_strlen(var) - 1)))
			return (i);
		i++;
	}
	return (-1);
}

int		display_env(t_env *e)
{
	int i;

	i = 0;
	while (e->env[i])
	{
		ft_putendl(e->env[i]);
		i++;
	}
	return (2);
}

char	*get_env(t_env *e, char *var)
{
	char	*env_var;
	int		i;

	i = search_env(e, var);
	if (i > -1)
		env_var = e->env[i] + ft_strlen(var) + 1;
	else
		env_var = ft_strdup("_");
	return (env_var);
}
