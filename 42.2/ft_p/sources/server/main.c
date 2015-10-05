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

int	process_client_cmd(int sock)
{
	char	buf[256];
	int	n;

	ft_bzero(buf, 256);
	n = 0;
	while (ft_strcmp(buf, "exit"))
	{
		ft_bzero(buf, 256);
		if ((n = read(sock, buf, 255)) < 0)
		{
			ft_putendl_fd("Read on socket error", 2);
			return (-1);
		}
		ft_putstr("Message from client : ");
		ft_putendl(buf);
		if ((n = write(sock, "Message received",18)) < 0)
		{
			ft_putendl_fd("Write on socket error", 2);
			return (-1);
		}
	}
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
