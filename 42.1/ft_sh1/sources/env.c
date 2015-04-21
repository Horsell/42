/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:32:51 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/18 05:48:54 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		search_env(t_env *e, char *var)
{
	int i;

	i = 1;
	while (e->env[i] != NULL)
	{
		if (!(ft_strncmp(e->env[i], var, ft_strlen(var) - 1)))
			return (i);
		i++;
	}
	return (0);
}

int		display_env(t_env *e)
{
	int i;

	i = 0;
	while (e->env[i])
	{
		ft_putendl(e->env[i]);
		i++;
	}
	return (2);
}

char	*get_env(t_env *e, char *var)
{
	char	*env_var;
	int		i;

	i = search_env(e, var);
	env_var = e->env[i] + ft_strlen(var) + 1;
	return (env_var);
}
