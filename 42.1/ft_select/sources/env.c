/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 16:24:42 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/10 16:19:24 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_env	*init_select(int ac, char **av)
{
	t_env			*e;

	if (!(e = malloc(sizeof(t_env))))
		return (NULL);
	if (!(e->win = malloc(sizeof(t_winsize))))
		return (NULL);
	initialize_terminal(av);
	e->clist = init_arglist(ac, av);
	e->nbargs = ac;
	ioctl(0, TIOCGWINSZ, e->win);
	return (e);
}

void	close_select(t_env *e)
{
	ft_clstdel(&e->clist);
	free(e->win);
	free(e);
	restore_term(1);
}

t_clist	*init_arglist(int ac, char **av)
{
	t_clist	*clist;
	t_clist	*first;
	t_clist	*tmp;
	int		i;

	i = 0;
	clist = NULL;
	while (i < ac)
	{
		if (!clist)
		{
			clist = ft_clstnew(av[i], 1);
			first = clist;
		}
		else
		{
			tmp = ft_clstnew(av[i], 0);
			ft_clstadd(&first->prev, &first, tmp);
		}
		i++;
	}
	return (clist);
}
