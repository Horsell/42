/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:54 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/03 16:31:11 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		ft_putc(int c)
{
	write(1, &c, 1);
	return (0);
}

static void	initialize_terminal(char **av)
{
	char		*term;
	t_termios	s_term;

	term = getenv("TERM");
	if (!term)
		exit(EXIT_FAILURE);
	tgetent(NULL, term);
	tcgetattr(0, &s_term);
	s_term.c_lflag &= ~(ICANON);
	s_term.c_lflag &= ~(ECHO);
	s_term.c_cc[VMIN] = 1;
	s_term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &s_term);
	tputs(tgetstr("vi", NULL), 1, ft_putc);
}

void	restore_term(int success)
{
	t_termios	s_term;

	tcgetattr(0, &s_term);
	s_term.c_lflag |= (ICANON);
	s_term.c_lflag |= (ECHO);
	tcsetattr(0, TCSADRAIN, &s_term);
	if (success != -42)
		tputs(tgetstr("cl", NULL), 1, ft_putc);
	tputs(tgetstr("ve", NULL), 1, ft_putc);
	exit(EXIT_SUCCESS);
}

	/*
//	while (ret != 1)
	{//
		line = ft_strdup("");
		prompt(e);
		while (buf[0] != 4)			
		{
			ft_bzero(buf, 4);
			read(0, buf, 4);
			x = (buf[3] << 24) + (buf[2] << 16) + (buf[1] << 8) + buf[0];
			if (x == 10)
			{
				ft_putchar('\n');
				ft_putstr(line);
				ret = check_cmd(line, e);
				free(line);
				line = NULL;
				line = ft_strdup("");
				if (ret == 1)
					break ;
				prompt(e);
			}
			else if (ft_isprint(x))
			{
				ft_putchar(buf[0]);
				line = ft_strjoin(line, buf);
			}
			else if (x == 9)
			{
				ft_putnbr(x);
			}
		}
//	}
	restore_term(1);
	ft_free(e);
	return (0);
}*/
