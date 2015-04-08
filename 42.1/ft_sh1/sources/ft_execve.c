/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:33:37 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/03 16:59:16 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_sh1.h"

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
			execve(cmd, av, env);
			exit(EXIT_FAILURE);
		}
	}
}
