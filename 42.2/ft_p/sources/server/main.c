/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/02 19:58:38 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
# include <dirent.h>

int	exec_ls(char *directory)
{
	DIR				*dir;
	struct dirent			*dp;

	dir = opendir(directory);
	while ((dp = readdir(dir)) != NULL)
	{
		ft_putendl(dp->d_name);
	}
	return (1);
}

int	check_cmd(char *line)
{
	if (!(ft_strcmp(line, "ls")))
	{
		ft_putstr("lalalalal");
		if (!(ft_strncmp(line, "..", 2)))
			return (-2);
		exec_ls(".");
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
	if ((n = read(sock, buf, 11)) > 0)
		len = ft_atoi(buf);
	else
	{
		ft_putendl_fd("Read length of message on socket error", 2);
		return (0);
	}
	return (len);
}

int	ft_read_sock(char **line, int sock)
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
		if (check_cmd(*line))
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

int	ft_write_sock(int sock)
{
	char	*confirm;
	int	n;

	confirm = ft_strdup("Message received");
	n = 0;
	if ((n = write(sock, confirm, 17)) < 0)
	{
		ft_putendl_fd("Write on socket error", 2);
		return (-1);
	}
	free(confirm);
	return (0);
}

int	process_client_cmd(int sock)
{
	char	*line;

	line = NULL;
	while (!line || ft_strcmp(line, "exit"))
	{
		if (!(ft_read_sock(&line, sock)))
			return (-1);
		ft_write_sock(sock);
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
			if (process_client_cmd(newsockfd) == -1)
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
