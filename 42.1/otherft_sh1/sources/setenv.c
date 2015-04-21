/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:32:56 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/17 18:25:24 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int	ft_setenv(t_env *e)
{
	char	*env_var;

	if (e->ac == 3)
	{
		e->env[e->ec] = malloc(sizeof(char) * 10);
		e->env[e->ec + 1] = malloc(sizeof(char) * 1);
		e->env[e->ec + 1] = NULL;
		env_var = ft_strjoin(e->av[1], "=");
		e->env[e->ec] = ft_strjoin(env_var, e->av[2]);
		ft_putendl(e->env[e->ec]);
	}
	else
		ft_putendl_fd("Syntax error, use : setenv var value", 2);
	return (2);
}
