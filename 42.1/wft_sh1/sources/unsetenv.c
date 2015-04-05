/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:32:45 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/04 21:35:19 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_sh1.h"

static char **ft_realloc(char **env, char *var, int n)
{
	char	**new_env;
	int		i;
	int		j;

	new_env = malloc(sizeof(char *) * n);
	i = 0;
	j = 0;
	while (j < n)
	{
		if (!(ft_strequ(env[i], var)))
		{
			new_env[j] = malloc(sizeof(char) * ft_strlen(env[i]));
			new_env[j] = env[i];
			i++;
		}
		j++;
	}
	free(env);
	return (new_env);
}

void	ft_unsetenv(t_env *e)
{
	int n;
	int j;

	if (!(e->env) || !(e->av[1]))
		return ;
	n = 0;
	while (e->env[n])
		n++;
	j = search_env(e, e->av[1]);
	if (j || ft_strnequ(e->av[1], e->env[0], ft_strlen(e->env[0])))
		e->env = ft_realloc(e->env, e->av[1], n - 1);
}
