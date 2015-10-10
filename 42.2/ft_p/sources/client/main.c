/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 17:41:54 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/08 12:03:09 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		ft_connect(t_env *e)
{
	if (connect(e->sockfd, (struct sockaddr*)&e->serv_addr, sizeof(e->serv_addr)) < 0)
	{
		ft_putendl_fd("Error on connect", 2);
		return (0);
	}
	return (1);
}

int		ft_send(t_env *e, char *str)
{
	char	*len;

	len = ft_itoa(ft_strlen(str) + 1);
	if (send(e->sockfd, len, 11, 0) < 0)
	{
		ft_putendl_fd("Socket send error", 2);
		return (0);
	}
	if (send(e->sockfd, str, ft_strlen(str), 0) < 0)
	{
		ft_putendl_fd("Socket send error", 2);
		return (0);
	}
	return (1);
}

int		ft_read(t_env *e)
{
	char	buf[18];
	int	n;

	if ((n = read(e->sockfd, buf, 17)) < 0)
	{
		return (0);
	}
	ft_putendl(buf);
	return (1);
}

int		ft_free(t_env *e)
{
	if (close(e->sockfd) == -1)
	{
		ft_putendl_fd("Socket close error", 2);
		return (0);
	}
	free(e);
	return (1);
}

int		main(int ac, char **av)
{
	t_env			*e;
	char				*line;
	
	if (ac != 2)
		return (-1);
	e = init_env(ft_atoi(av[1]));
	if (ft_connect(e))
	{
		prompt(e);
		while (get_next_line(0, &line))
		{
			if (!(ft_strcmp(line, "quit")))
				break ;
			ft_send(e, line);
			if (!(ft_read(e)))
				ft_putendl("read log error");
			prompt(e);
		}
		free(line);
	}
	ft_free(e);
	return (0);
}

//	struct hostent		*hostinfo;
//	addr = { 0 }; // initialise la structure avec des 0 
