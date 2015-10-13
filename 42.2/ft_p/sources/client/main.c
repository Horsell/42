/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 17:41:54 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/13 14:25:42 by jpirsch          ###   ########.fr       */
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

int	ft_read_len(int sock)
{
	char	buf[11];
	int	len;
	int	n;

	len = 0;
	n = 0;
	if ((n = read(sock, buf, 11)) >= 0)
		len = ft_atoi(buf);
	else
	{
		ft_putendl_fd("Read length of message on socket error", 2);
		return (0);
	}
	return (len);
}

int	ft_read_sock(int sock)
{
	char *line;
	int	n;
	int	len;

	n = 0;
	len = ft_read_len(sock);
	line = ft_strnew(len);
	ft_bzero(line, len);
	if ((n = read(sock, line, len)) > 0)
	{
		ft_putstr("Message from server : ");
		ft_putendl(line);
	}
	if (n < 0)
	{
		ft_putendl_fd("Read on socket error", 2);
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
		ft_putendl_fd("Read confirm message on socket error", 2);
		return (0);
	}
	ft_putendl(buf);
	ft_read_sock(e->sockfd);
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
	t_env	*e;
	char	*line;
	
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
			if (!(ft_send(e, line)))
				return (-1);
			if (!(ft_read(e)))
				return (-1);
			prompt(e);
//			if (!(prompt(e)))
//				return (-1);
		}
		free(line);
	}
	ft_free(e);
	return (0);
}

//	struct hostent		*hostinfo;
//	addr = { 0 }; // initialise la structure avec des 0 
