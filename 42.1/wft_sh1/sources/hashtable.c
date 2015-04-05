/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:49 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/04 22:14:55 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "libft.h"
#include "ft_sh1.h"

int		check_path(t_env *e)
{
	int				i;
	char			*path;
	char			**tab_path;
	char			*join;
	DIR				*dir;
	struct dirent	*dp;

	dir = opendir(".");
	while ((dp = readdir(dir)) != NULL)
	{
		ft_putendl(dp->d_name);
	}
	i = 1;
	while (e->path[i])
	{
		join = ft_strjoin(e->path[i], "/");
		join = ft_strjoin(join, e->av[0]);
		ft_execve(join, e->av, e->env);
		i++;
	}
	return (--i);
}
