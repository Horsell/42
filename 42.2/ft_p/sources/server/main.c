/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/13 14:34:45 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
# include <dirent.h>

int	check_cmd(char *line, t_env *e)
{
	e->av = ft_strsplit(line, ' ');
	e->av[0] = ft_strjoin("/bin/", e->av[0]);
	ft_exec(e);
	return (1);
}

int	ft_read_len(int sock)
{
	char	buf[11];
	int	len;
	int	n;

	len = 0;
	n = 0;
	if ((n = read(sock, buf, 11)) > 0)
		len = ft_atoi(buf);
	else
	{
		ft_putendl_fd("Read length of message on socket error", 2);
		return (0);
	}
	return (len);
}

int	ft_read_sock(char **line, int sock, t_env *e)
{
	int	n;
	int	len;

	n = 0;
	len = ft_read_len(sock);
	*line = ft_strnew(len);
	ft_bzero(*line, len);
	if ((n = read(sock, *line, len)) > 0)
	{
		ft_putstr("Message from client : ");
		ft_putendl(*line);
		if (check_cmd(*line, e))
		{
			return (2);
		}
	}
	if (n < 0)
	{
		ft_putendl_fd("Read on socket error", 2);
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
		ft_putendl_fd("Socket send len error", 2);
		return (0);
	}
	if (send(e->sockfd, str, ft_strlen(str), 0) < 0)
	{
		ft_putendl_fd("Socket send error", 2);
		return (0);
	}
	return (1);
}

int	ft_write_sock(int sock, char *line)//, t_env *e)
{
	char	*confirm;
	int	n;
	t_env	bricolage;

	bricolage.sockfd = sock;
	confirm = ft_strdup("Message received");
	n = 0;
	if ((n = write(sock, confirm, 17)) < 0)
	{
		ft_putendl_fd("Write on socket error", 2);
		return (0);
	}
	free(confirm);
	ft_send(&bricolage, line);
	return (0);
}

int	process_client_cmd(int sock, t_env *e)
{
	char	*line;

	line = NULL;
	while (!line || ft_strcmp(line, "quit"))
	{
//		if (!(result_cmd = ft_read_sock(&line, sock, e)))
		if (!(ft_read_sock(&line, sock, e)))
			return (0);
		if (!(ft_write_sock(sock, line)))//, e)))
			return (0);
	}
	free(line);
	return (0);
}

int		main(int ac, char **av)
{
	t_env			*e;
	struct sockaddr_in	cli_addr;
	int					newsockfd;
	int					clilen;
	int					pid;

	/* Now start listening for the clients, here
	* process will go in sleep mode and will wait
	* for the incoming connection
	*/
	if (ac != 2)
	{
		ft_putendl_fd("Wrong number of arguments, use : ./server portnumber", 2);
		return (-1);
	}
	if (!(e = init_env(ft_atoi(av[1]))))
		return (-1);
	listen(e->sockfd,5);
	clilen = sizeof(cli_addr);
	while (1)
	{
		newsockfd = accept(e->sockfd, (struct sockaddr*)&cli_addr, (socklen_t*)&clilen);
		if (newsockfd < 0)
		{
			ft_putendl_fd("Socket accept error", 2);
			return (-1);
		}
		/* Create child process */
		pid = fork();
		if (pid < 0)
		{
			ft_putendl_fd("Fork error", 2);
			return (-1);
		}
		if (pid == 0)
		{
			/* This is the client process */
			close(e->sockfd);
			if (!(process_client_cmd(newsockfd, e)))
			{
				ft_putendl_fd("A client / server process failed", 2);
				return (-1);
			}
		}
		else
			close(newsockfd);
	}
	return (0);
}
