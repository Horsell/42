/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/04 18:21:03 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	catch(int signum)
{
	ft_putstr("io");
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

int		main(int ac, char **av, char **env)
{
	t_list			*list;
	t_list			*tmp;
	char			chain[9];
	int				ret;
	int				fd;
	char			*underline;
	struct winsize	win;

	(void)env;
	signal(SIGINT, catch);
	signal(SIGWINCH, catch);
	initialize_terminal(av);
	fd = open("/dev/tty", O_WRONLY);
	underline = tgetstr("us", NULL);
	tputs(underline, 1, ft_putc);
	ioctl(0, TIOCGWINSZ, &win);
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
		ft_putendl_fd(list->content, fd);
		if (list->next)
			list = list->next;
		else
			break ;
	}
	int i = 0;
	while (i < win.ws_row - 4)
	{
		tputs(tgetstr("up", NULL), 1, ft_putc);
		tputs(tgetstr("dl", NULL), 1, ft_putc);
		i++;
	}
	while (read(0, chain, 2))
	{
		if (chain[0] == '\t')
			ft_putnbr(chain[0]);
		if (chain[0] == '\n')
			break ;
	}
	tputs(tgetstr("so", NULL), 1, ft_putc);
	ft_putchar('f');
	tputs(tgetstr("le", NULL), 1, ft_putc);
	ft_putchar('o');
//	tputs(tgetstr("RI", NULL), 1, ft_putc);
	tputs(tgetstr("me", NULL), 1, ft_putc);
	ft_putchar('\n');
	ft_putnbr(win.ws_row);
	ft_putchar('\n');
	ft_putnbr(win.ws_col);
	ft_putchar('\n');
	ft_putstr_fd("lskf", 1);
	sleep(2);
//	underline = tgetstr("ue", NULL);
	tputs(underline, 1, ft_putc);
	close(fd);
	restore_term(1);
	return (0);
}
