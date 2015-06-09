/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 14:17:27 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/09 14:18:04 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	catch(int signum)
{
	(void)signum;
	ft_putstr("\b\b");
}

void	signals()
{
	signal(SIGINT, catch);
	signal(SIGWINCH, catch);
}
