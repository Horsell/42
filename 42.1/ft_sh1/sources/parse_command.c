/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:36 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/04 13:16:10 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_sh1.h"

int		check_builtin(char *line, char **env, char **av)
{
	int		ret;

	ret = 1;
	ret = (ft_strcmp(line, "exit")) ? 0 : 1;
	(ft_strequ(line, "env")) ? display_env(env) : 2;
	if (ft_countwords(line, ' ') > 1)
		(ft_strnequ(line, "unsetenv ", 9)) ? ft_unsetenv(env, av[1]) : 2;
	return (ret);
}

int		check_command(char *line, char **argv, char **env)
{
	int		ret;
	int		i;
	char	**av;

	av = ft_strsplit(line, ' ');
	//i = ft_countwords(line, ' ');
	//av[i] = NULL;
	ret = check_builtin(line, env, av);
	(ret == 1) ? check_path(env, av, line) : 1;
	return (ret);
}
