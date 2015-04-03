/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:36 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/03 16:59:22 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_sh1.h"

int		check_builtin(char *line, char **env)
{
	int		ret;

	ret = 1;
	ret = (ft_strcmp(line, "exit")) ? 0 : 1;
	(ft_strcmp(line, "env")) ? 1 : display_env(env);
	return (ret);
}

int		check_command(char *line, char **av, char **env)
{
	int ret;

	ret = check_builtin(line, env);
	check_path(env, av, line);
		//	ft_putstr("Command not found");
	return (ret);
}
