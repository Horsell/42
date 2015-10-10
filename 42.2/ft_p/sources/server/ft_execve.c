/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 12:05:53 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/08 12:06:05 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_exec(t_env *e)
{
	ft_execve(ft_strchr(e->av[0], '/') + 1, e->av, e->env);
	return (2);
}

void	ft_execve(char *cmd, char **av, char **env)
{
	pid_t	father;

	if (cmd != NULL)
	{
		father = fork();
		if (father > 0)
			wait(NULL);
		if (father == 0)
		{
			signal(SIGINT, SIG_DFL);
			execve(cmd, av, env);
			exit(EXIT_FAILURE);
		}
	}
}
