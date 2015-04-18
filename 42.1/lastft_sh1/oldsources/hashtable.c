/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:49 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/08 08:43:04 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	hash(t_env *e)
{
	int				i;
	DIR				*dir;
	char			*cmd_path;
	struct dirent	*dp;
	t_list			*new;

	i = 0;
	while (i < e->ec)
	{
		if ((dir = opendir(e->path[i])))
		{
			while ((dp = readdir(dir)) != NULL)
			{
				if ((ft_strncmp(dp->d_name, "..", 2)) ||
						(ft_strncmp(dp->d_name, ".", 1)))
				{
					cmd_path = ft_strjoin(e->path[i], "/");
					cmd_path = ft_strjoin(cmd_path, dp->d_name);
					new = ft_lstnew(cmd_path, ft_strlen(cmd_path));
					ft_lstadd(&e->hash, new);
					if (e->hash)
					{
			ft_putendl(e->hash->content);
					}
				}
			}
			closedir(dir);
		}
		i++;
	}
}

int		check_path(t_env *e)
{
	int				i;
	int				n;
	char			*path;
	char			**tab_path;
	char			*join;

//	hash(e);
	i = 0;
	while (i < e->pc)
	{
		join = ft_strjoin(e->path[i], "/");
		join = ft_strjoin(join, e->av[0]);
		ft_execve(join, e->av, e->env);
		i++;
	}
	return (--i);
}
