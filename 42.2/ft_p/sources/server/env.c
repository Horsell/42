/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/08 13:33:01 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_env	*init_env(int portno)
{
	t_env	*e;

	if (!portno)
	{
		ft_putendl_fd("Bad argument", 2);
		return (NULL);
	}
	e = empty_env();
	/* First call to socket() function */
	e->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (e->sockfd < 0)
	{
		ft_putendl_fd("Socket attribution error", 2);
		return (NULL);
	}
	/* Initialize socket structure */
	ft_bzero((char*)&e->serv_addr, sizeof(e->serv_addr));
	e->serv_addr.sin_family = AF_INET;
	e->serv_addr.sin_addr.s_addr = INADDR_ANY;
	e->serv_addr.sin_port = htons(portno);
	/* Now bind the host address using bind() call.*/
	if (bind(e->sockfd, (struct sockaddr *) &e->serv_addr, sizeof(e->serv_addr)) < 0)
	{
		ft_putendl_fd("Socket binding error", 2);
		return (NULL);
	}
/*	char	*pwd;

	pwd = ft_strnew(512);
	pwd = getcwd(pwd, sizeof(pwd));
	e->env = malloc(sizeof(char *) * 4);
	e->env[0] = malloc(sizeof(char) * ft_strlen(pwd));
	ft_strcpy(e->env[0], pwd);
	free(pwd);*/
	return (e);
}


t_env	*empty_env(void)
{
	t_env 	*e;
	char	buf[256];

	if (!(getcwd(buf, 256)))
	{
			ft_putendl_fd("Error : failed to load current directory", 2);
			return (NULL);
	}
	e = malloc(sizeof(t_env));
	e->env = malloc(sizeof(char*) * 1);
	e->ec = 0;
	ft_setenv_prog(e, "PWD", buf);
	ft_setenv_prog(e, "USER", "unknown");
	ft_setenv_prog(e, "HOME", "/");
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
