/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/17 18:26:28 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void	prompt(t_env *e)
{
	int i;

	i = 0;
	if (e->env == NULL)
		ft_putstr(" >");
	else
	{
		ft_putstr(C_RED);
		ft_putstr(get_env(e, "USER"));
		ft_putstr(C_BLUE);
		ft_putstr("@");
		ft_putstr(C_BROWN);
		ft_putstr(get_env(e, "PWD"));
		ft_putstr(C_NONE);
		ft_putstr("/>");
	}
}

static t_env	*empty_env()
{
	t_env 	*e;

	//getcwd(char * buf, size_t size)
	ft_putendl_fd("Error : empty environment.", 2);
	return (e);
}

int		main(int ac, char **av, char **env)
{
	char	*line;
	int		ret;
	t_env 	*e;
	char	*path;

	ret = 0;
	e = (!(env[0])) ? empty_env() : init_env(env);
	while (ret != 1)
	{
		prompt(e);
		if (get_next_line(0, &line))
		{
			ret = check_cmd(line, e);
			if (ret == 1)
				break ;
		}
	}
	return (0);
}
