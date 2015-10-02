/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 17:41:54 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/02 20:05:08 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

int		main(void)
{
	struct sockaddr_in	serv_addr;
	char				*str;
	int					sockfd;
	
//	struct hostent		*hostinfo;
//	SOCKADDR_IN addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		ft_putendl_fd("Socket attribution error", 2);
		return (-1);
	}
//	addr = { 0 }; // initialise la structure avec des 0 
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(4242); // on utilise htons pour le port 
	if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		ft_putendl_fd("Error on connect", 2);
		return (-1);
	}
	str = ft_strdup("Hello world !");
	if (send(sockfd, str, ft_strlen(str), 0) < 0)
	{
		ft_putendl_fd("Socket attribution error", 2);
		return (-1);
	}
	free(str);
	close(sockfd);
	return (0);
}
