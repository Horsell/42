/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 17:41:54 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/02 20:05:08 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	prompt(t_env *e)
{
	(void)e;
	ft_putstr("Enter a cmd to send > ");
/*	char *pwd;
	char *user;

	user = get_env(e, "USER");
	pwd = get_env(e, "PWD");
	if (user[0] != '_')
	{
		ft_putstr(C_RED);
		ft_putstr(user);
	}
	ft_putstr(C_BLUE);
	ft_putstr("@");
	if (pwd[0] != '_')
	{
		ft_putstr(C_BROWN);
		ft_putstr(pwd);
	}
	ft_putstr(C_NONE);
	ft_putstr("/>"); */
}

t_env	*init_env(int portno)
{
	t_env	*e;

	if (!portno)
		return (NULL);
	e = malloc(sizeof(t_env));
	if (!e)
	{
		ft_putendl_fd("Malloc error", 2);
		return (NULL);
	}
	e->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (e->sockfd < 0)
	{
		ft_putendl_fd("Socket attribution error", 2);
		free(e);
		return (NULL);
	}
	ft_bzero((char*)&e->serv_addr, sizeof(e->serv_addr));
	e->serv_addr.sin_family = AF_INET;
	e->serv_addr.sin_addr.s_addr = INADDR_ANY;
	e->serv_addr.sin_port = htons(portno); // on utilise htons pour le port 
	return (e);
}
