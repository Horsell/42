/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_modes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 18:49:58 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/04 18:56:48 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	clear()
{
	int i = 0;
	while (i < win.ws_row - 4)
	{
		tputs(tgetstr("up", NULL), 1, ft_putc);
		tputs(tgetstr("dl", NULL), 1, ft_putc);
		i++;
	}
}

void	invert_color(t_env *e)
{
	tputs(tgetstr(INVERT_COLOR, NULL), 1, ft_putc);
}

void	reinvert_color(t_env *e)
{
	tputs(tgetstr(REINVERT_COLOR, NULL), 1, ft_putc);
}

void	underline(t_env *e)
{
	tputs(tgetstr(UNDERLINE_ON, NULL), 1, ft_putc);
}

void	underline_off(t_env *e)
{
	tputs(tgetstr(UNDERLINE_OFF, NULL), 1, ft_putc);
}

