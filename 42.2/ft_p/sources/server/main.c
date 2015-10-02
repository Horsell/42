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

#include "ft_p.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

void	doprocessing(int sock)
{
	int n;
	char buffer[256];

	bzero(buffer,256);
	n = read(sock,buffer,255);
	if (n < 0)
	{
		perror("ERROR reading from socket");
		exit(1);
	}
	printf("Here is the message: %s\n",buffer);
	n = write(sock,"I got your message",18);
	if (n < 0)
	{
		perror("ERROR writing to socket");
		exit(1);
	}
}

int		main(void)//int ac, char **av)
{
	struct sockaddr_in	serv_addr;
	struct sockaddr_in	cli_addr;
	int					sockfd;
	int					newsockfd;
	int					portno;
	int					clilen;
	int					pid;

	/* First call to socket() function */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		perror("ERROR opening socket");
		exit(1);
	}
	/* Initialize socket structure */
	bzero((char*)&serv_addr, sizeof(serv_addr));
	portno = 4242;

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	/* Now bind the host address using bind() call.*/
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		perror("ERROR on binding");
		exit(1);
	}
	/* Now start listening for the clients, here
	* process will go in sleep mode and will wait
	* for the incoming connection
	*/
	listen(sockfd,5);
	clilen = sizeof(cli_addr);
	while (1)
	{
		newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, (socklen_t*)&clilen);
		if (newsockfd < 0)
		{
			perror("ERROR on accept");
			exit(1);
		}
		/* Create child process */
		pid = fork();
		if (pid < 0)
		{
			perror("ERROR on fork");
			exit(1);
		}
		if (pid == 0)
		{
			/* This is the client process */
			close(sockfd);
			doprocessing(newsockfd);
			exit(0);
		}
		else
			close(newsockfd);
	}
	return (0);
}