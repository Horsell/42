/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 08:41:37 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/17 18:30:00 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int	ft_cd(t_env *e)
{
	char	*pwd;
	char	*oldpwd;

	if (e->ac > 1)
	{
		pwd = e->av[1];
		oldpwd = get_env(e, "PWD") + 4;
		e->env[search_env(e, "PWD")] = ft_strjoin("PWD=", pwd);
		e->env[search_env(e, "OLDPWD")] = ft_strjoin("OLDPWD=", oldpwd);
	}
	return (2);
}
