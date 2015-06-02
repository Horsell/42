/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 16:24:42 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/02 16:25:01 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		search_env(t_env *e, char *var)
{
	int i;

	i = 0;
	while (e->env[i] != NULL)
	{
		if (!(ft_strncmp(e->env[i], var, ft_strlen(var) - 1)))
			return (i);
		i++;
	}
	return (-1);
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
	if (i > -1)
		env_var = e->env[i] + ft_strlen(var) + 1;
	else
		env_var = ft_strdup("_");
	return (env_var);
}
