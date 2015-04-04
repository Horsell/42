/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:49 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/03 16:59:24 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_sh1.h"

int		check_path(char **env, char **av, char *bin)
{
	int		i;
	char	*path;
	char	**tab_path;
	char	*join;

	i = search_env(env, "PATH");
	path = &env[i][ft_strlen("PATH") + 1];
	tab_path = ft_strsplit(path, ':');
	i = 1;
	while (tab_path[i])
	{
		join = ft_strjoin(tab_path[i], "/");
		join = ft_strjoin(join, bin);
		ft_execve(join, av, env);
		i++;
	}
	return (--i);
}
