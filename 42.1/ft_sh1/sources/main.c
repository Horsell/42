/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/03 17:00:16 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_sh1.h"

void	prompt(char **env)
{
	int i;

	i = 0;
	if (env == NULL)
		ft_putstr(" >");
	else
	{
		i = search_env(env, "USER");
		ft_putstr(C_RED);
		ft_putstr(&env[i][ft_strlen("USER") + 1]);
		ft_putstr(C_BLUE);
		ft_putstr("@");
		ft_putstr(C_BROWN);
		i = search_env(env, "PWD");
		ft_putstr(&env[i][ft_strlen("PWD") + 1]);
		ft_putstr(C_NONE);
		ft_putstr("/>");
	}
}

int		main(int ac, char **av, char **env)
{
	char	*line;
	int		ret;

	ret = 0;
	while (ret == 0)
	{
			prompt(env);
		if (get_next_line(0, &line))
		{
			ret = check_command(line, av, env);
			if (ret == 1)
				break;
		}
	}
	return (0);
}
