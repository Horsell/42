/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:32:51 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/03 16:59:18 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_sh1.h"

int		search_env(char **env, char *var)
{
	int i;

	i = 1;
	while (env[i] != NULL)
	{
		if (!(ft_strncmp(env[i], var, ft_strlen(var) - 1)))
			return (i);
		i++;
	}
	return (0);
}

void	display_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}
