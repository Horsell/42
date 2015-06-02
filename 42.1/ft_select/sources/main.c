/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/02 16:55:33 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	catch(int signum)
{
	ft_putstr("\b\b");
}


void		activate_underline(t_list **list)
{
	char	*dir;
	char	*videomod;
	char	*disable;
	char	*underline;

	dir = tgetstr("cm", NULL);
	videomod = tgetstr("so", NULL);
	disable = tgetstr("me", NULL);
	underline = tgetstr("us", NULL);
	tputs(underline, 1, ft_putc);
	if ((*list)->content)
		tputs(videomod, 1, ft_putc);
	tputs(tgoto(dir, 2, 5), 1, ft_putc);
	ft_putendl_fd((*list)->content, 2);
	tputs(disable, 1, ft_putc);
	tputs(tgoto(dir, 2, 5), 1, ft_putc);
}

int		main(int ac, char **av, char **env)
{
	t_list	*list;
	t_list	*tmp;

	(void)env;
	
	signal(SIGINT, catch);
	initialize_terminal(av);
	while (--ac >= 0)
	{
		if (!list)
			list = ft_lstnew(av[ac], sizeof(char) * ft_strlen(av[ac]));
		else
		{
			tmp = ft_lstnew(av[ac], sizeof(char) * ft_strlen(av[ac]));
			ft_lstadd(&list, tmp);
		}
	}
	while (list)
	{
		ft_putendl(list->content);
		if (list->next)
			list = list->next;
		else
			break ;
	}
	sleep(2);
	restore_term(1);
	return (0);
}
