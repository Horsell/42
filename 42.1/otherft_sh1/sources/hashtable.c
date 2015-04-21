/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:49 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/21 05:23:32 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	hash_t(t_env *e, char *path_dir, char *bin, int i)
{
	t_list			*new;
	char			*cmd_path;

	cmd_path = ft_strjoin(path_dir, "/");
	cmd_path = ft_strjoin(cmd_path, bin);
	if (i == 0)
		e->hash = ft_lstnew(&cmd_path, sizeof(char*) * ft_strlen(cmd_path));
	else
		new = ft_lstnew(&cmd_path, sizeof(char*) * ft_strlen(cmd_path));
	ft_lstadd(&e->hash, new);
}

int		hash(t_env *e, char *bin, int j)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (bin[i])
	{
		k += bin[i]; 
		i++;
	}
	k = k % j;
	while ((e->hashtab[k]))
		k++;
	return (k);
}

int		rev_hash(t_env *e, char *bin)
{
	int		i;
	int		k;
	char	*hashbin;

	i = 0;
	k = 0;
	while (bin[i])
	{
		k += bin[i]; 
		i++;
	}
	k = k % e->hc;
	while ((e->hashtab[k]))
	{
		hashbin = ft_strrchr(*(char**)e->hashtab[k]->content, '/') + 1;
		if (!(ft_strcmp(bin, hashbin)))
			return (k);
		k++;
	}
	return (k);
}

void	hash_table(t_env *e, int j)
{
	t_list			*tmp;
	int				n;
	char			*bin;

	e->hashtab = malloc(sizeof(int) * j + 1);
	tmp = e->hash;
	n = 0;
	while (n < j + 1)
	{
		e->hashtab[n] = NULL;
		n++;
	}
	while (tmp->next)
	{
		bin = ft_strrchr(*(char**)tmp->content, '/') + 1;
		n = hash(e, bin, j);
		e->hashtab[n] = tmp;
		tmp = tmp->next;
	}
	e->hc = j + 1;
}

void	read_path(t_env *e)
{
	int				i;
	int				j;
	DIR				*dir;
	struct dirent	*dp;

	i = 0;
	j = 1;
	while (i < e->pc)
	{
		if ((dir = opendir(e->path[i])))
		{
			while ((dp = readdir(dir)))
			{
				if ((ft_strncmp(dp->d_name, "..", 2)) &&
						(ft_strncmp(dp->d_name, ".", 1)))
				{
					hash_t(e, e->path[i], dp->d_name, i);
					j++;
				}
			}
			closedir(dir);
		}
		i++;
	}
	hash_table(e, j);
}

int		check_path(t_env *e)
{
	int		i;
	int		n;
	char	*hashbin;

	i = 0;
	/*if (e->av[0][0] == '/')
	{
		ft_execve(e->av[0], e->av, e->env);
		return (0);
	}*/
	n = rev_hash(e, e->av[0]);
	hashbin = ft_strrchr(*(char**)e->hashtab[n]->content, '/') + 1;
	if (!(ft_strcmp(hashbin, e->av[0])))
		ft_execve(*(char**)e->hashtab[n]->content, e->av, e->env);
	else
		ft_putendl_fd("Command not found.", 2);
	return (--i);
}
