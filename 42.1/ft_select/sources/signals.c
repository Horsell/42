/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 14:17:27 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/10 17:01:04 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	catch(int signum)
{
	char			sim[2];
	struct termios	*new;

	if (signum == 18)
	{
		restore_term(1);
		sim[0] = new->c_cc[VSUSP];
		sim[1] = 0;
		ioctl(0, TIOCSTI, sim);
		signal(SIGTSTP, SIG_DFL);
	}
	//	ft_putstr("\b\b");
}

void	signals()
{
	signal(SIGINT, catch);
	signal(SIGWINCH, catch);
	signal(SIGTSTP, catch);
}
