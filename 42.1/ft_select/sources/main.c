/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/08 08:35:21 by jpirsch          ###   ########.fr       */
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
	ft_putendl_fd((*list)->content, 1);
	tputs(disable, 1, ft_putc);
	tputs(tgoto(dir, 2, 5), 1, ft_putc);
}

t_list	*init_arglist(int ac, char **av)
{
	t_list			*list;
	t_list			*tmp;

	list = NULL;
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
	return (list);
}

void	display_args(t_list *list)
{
	while (list)
	{
		
		ft_putendl(list->content);
		if (list->next)
			list = list->next;
		else
			return ;
	}
}

void	clr_screen()
{
	int i;

	i = 0;
	while (i < 44)
	{
		tputs(tgetstr("up", NULL), 1, ft_putc);
		tputs(tgetstr("dl", NULL), 1, ft_putc);
		i++;
	}
}

t_env	*init(int ac, char **av)
{
	t_env			*e;
	t_list			*list;
	struct winsize	win;

	if (!(e = malloc(sizeof(t_env))))
		return (NULL);
	initialize_terminal(av);
	ioctl(0, TIOCGWINSZ, &win);
	list = init_arglist(ac, av);
	tputs(tgetstr("cl", NULL), 1, ft_putc);
	return (e);
}

void	select_elem()
{
}

void	myread()
{
	char	buf[4];
	int		x;

	x = 0;
	while (buf[0] != 4)			
	{
		buf[0] = 0;
		buf[1] = 0;
		buf[2] = 0;
		buf[3] = 0;
		read(0, buf, 4);
		x = (buf[3] << 24) + (buf[2] << 16) + (buf[1] << 8) + buf[0];
		if (x == 27)
			break ;
		if (x == 32)
			select_elem();
     }
}

void	signals()
{
	signal(SIGINT, catch);
	signal(SIGWINCH, catch);
}

int		main(int ac, char **av)
{
	t_list			*list;
	struct winsize	win;

	signals();
		ft_putstr("\033[?1049h\033[H");
	initialize_terminal(av);
//	ioctl(0, TIOCGWINSZ, &win);
	tputs(tgetstr("cl", NULL), 1, ft_putc);
	list = init_arglist(ac, av);
	display_args(list);
	myread();
		ft_putstr("\033[?1049l");
	restore_term(1);
	return (0);
}
