/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/14 11:56:55 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void	prompt(t_env *e)
{
	char *pwd;
	char *user;

	user = get_env(e, "USER");
	pwd = get_env(e, "PWD");
	if (user[0] != '_')
	{
		ft_putstr(C_RED);
		ft_putstr(user);
	}
	ft_putstr(C_BLUE);
	ft_putstr("@");
	if (pwd[0] != '_')
	{
		ft_putstr(C_BROWN);
		ft_putstr(pwd);
	}
	ft_putstr(C_NONE);
	ft_putstr("/>");
}

void	ft_free(t_env *e)
{
	int	i;

	i = -1;
	if (e)
	{
		if (e->av)
			while (++i < e->ac)
				free(e->av[i]);
		free(e->av);
		free(e);
	}
}

void	catch(int signum)
{
	ft_putstr("\b\b");
}


int		main(int ac, char **av, char **env)
{
	char			*line;
	int			ret;
	t_termios		*term;
	t_env 			*e;

	ret = 0;
	e = (!(env[0])) ? empty_env() : init_env(env);
	signal(SIGINT, catch);
	while (ret != 1)
	{
		prompt(e);
		if (get_next_line(0, &line)) // --> term_saisie for sh3
			ret = parse_cmd(line, e);
//			ret = ft_excmd_tree(e);   --> Exec, pipes and dup according to parsed tree
//			ret = check_cmd(line, e); ooold (sh1)
	}
	ft_free(e);
	return (0);
}
