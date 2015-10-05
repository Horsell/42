/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/02 19:58:38 by jpirsch          ###   ########.fr       */
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
	if (!(e = malloc(sizeof(t_env))))
	{
		ft_putendl_fd("Malloc error", 2);
		return (NULL);
	}
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
	return (e);
}
