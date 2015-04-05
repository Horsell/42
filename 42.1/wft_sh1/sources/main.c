/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/04 22:22:02 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_sh1.h"

void	prompt(t_env *e)
{
	int i;

	i = 0;
	if (e->env == NULL)
		ft_putstr(" >");
	else
	{
		ft_putstr(C_RED);
		ft_putstr(get_env(e, "USER") + 5);
		ft_putstr(C_BLUE);
		ft_putstr("@");
		ft_putstr(C_BROWN);
		ft_putstr(get_env(e, "PWD") + 4);
		ft_putstr(C_NONE);
		ft_putstr("/>");
	}
}

int		main(int ac, char **av, char **env)
{
	char	*line;
	int		ret;
	t_env 	*e;

	ret = 0;
	e = init_env(env);
	while (ret == 0)
	{
		prompt(e);
		if (get_next_line(0, &line))
		{
			ret = check_cmd(line, e);
			if (ret == 1)
				break;
		}
	}
	return (0);
}
