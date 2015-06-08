/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sing.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 11:41:20 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/03 11:41:25 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					sing_tty(void)
{
	static int		fd = -1;

	if (fd == -1)
		fd = open("/dev/tty", O_WRONLY);
	return (fd);
}

t_select			*sing_select(t_select *new)
{
	static t_select		*arg;

	if (new != NULL)
		arg = new;
	return (arg);
}

struct termios		*sing_oldterm(struct termios *term)
{
	static struct termios	*old;

	if (term != NULL)
		old = term;
	return (old);
}

struct termios		*sing_newterm(struct termios *term)
{
	static struct termios	*new;

	if (term != NULL)
		new = term;
	return (new);
}
