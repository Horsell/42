/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:54 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/09 20:04:33 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_putc(int c)
{
	write(1, &c, 1);
	return (0);
}

void	initialize_terminal()
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
	tcsetattr(0, TCSADRAIN, &s_term);
	tputs(tgetstr("vi", NULL), 1, ft_putc);
		ft_putstr("\033[?1049h\033[H");
}

void	restore_term(int success)
{
	t_termios	s_term;

	success = -42;
	tcgetattr(0, &s_term);
	s_term.c_lflag |= (ICANON);
	s_term.c_lflag |= (ECHO);
	tcsetattr(0, TCSADRAIN, &s_term);
		ft_putstr("\033[?1049l");
	if (success != -42)
		tputs(tgetstr("cl", NULL), 1, ft_putc);
	tputs(tgetstr("ve", NULL), 1, ft_putc);
	exit(EXIT_SUCCESS);
}
