/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:32:45 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/04 13:15:16 by jpirsch          ###   ########.fr       */
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

void	ft_unsetenv(char **env, char *var)
{
	int n;
	int j;

	if (!(env) || !(var))
		return ;
	n = 0;
	while (env[n])
		n++;
	j = search_env(env, var);
	if (j || ft_strnequ(var, env[0], ft_strlen(env[0])))
		env = ft_realloc(env, var, n - 1);
}
