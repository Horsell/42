/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/08 05:47:37 by jpirsch          ###   ########.fr       */
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

int		main(int ac, char **av, char **env)
{
	t_list			*list;
	char			chain[9];
	int				ret;
	int				fd;
	char			*underline;
	struct winsize	win;

	(void)env;
	signal(SIGINT, catch);
	signal(SIGWINCH, catch);
	initialize_terminal(av);
//	fd = open("/dev/tty", O_WRONLY);
//	underline = tgetstr("us", NULL);
//	tputs(underline, 1, ft_putc);
	ioctl(0, TIOCGWINSZ, &win);
	clr_screen();
	list = init_arglist(ac, av);
	display_args(list);
	while (read(0, chain, 2))
	{
		ft_putchar(chain[0]);
		if (chain[0] == '\t')
			ft_putnbr(chain[0]);
		if (chain[0] == '\n')
			break ;
	}
//	tputs(tgetstr("so", NULL), 1, ft_putc);
	tputs(tgetstr("le", NULL), 1, ft_putc);
//	tputs(tgetstr("RI", NULL), 1, ft_putc);
//	tputs(tgetstr("RI", NULL), 1, ft_putc);
	ft_putstr("gome");
	tputs(tgetstr("me", NULL), 1, ft_putc);
	ft_putchar('\n');
	ft_putnbr(win.ws_row);
	ft_putchar('\n');
	ft_putnbr(win.ws_col);
	ft_putchar('\n');
	sleep(2);
	underline = tgetstr("ue", NULL);
	tputs(underline, 1, ft_putc);
	close(fd);
	restore_term(1);
	return (0);
}
