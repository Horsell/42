/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:36 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/12 14:28:32 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		is_op(char *line, int *i)
{
	if (is_pipe(line, i))
		return (PIPE);
	if (is_l_red(line, i))
		return (L_RED);
	if (is_r_red(line, i))
		return (R_RED);
	if (is_ll_red(line, i))
		return (LL_RED);
	if (is_rr_red(line, i))
		return (RR_RED);
	return (0);
}

int		is_reserved_char(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == ';' || c == 92 || c == '"') // todo : handle \ and "
		return (1);
	else
		return (0);
}

int		is_word(char *line, int *i)
{
	if (is_reserved_char(line[*i]) || ft_isprint(line[*i]) == 0)
		return (0);
	if (ft_isspace(line[*i]))
	{
		while (ft_isspace(line[*i]) && line[*i])
			(*i)++;
		if (!ft_isprint(line[*i]) || !line[*i])
			return (0);
	}
	while (ft_isprint(line[*i]))
	{
		if (is_reserved_char(line[*i]))
			return (1);
		if (ft_isspace(line[*i])) //todo implement true isspace
		{
			while (ft_isspace(line[*i]))
				(*i)++;
			return (1);
		}
		(*i)++;
	}
	return (1);
}

int		is_cmd(char *line, int *i)
{
	return (1);
}

int		ft_build_symbol_table(char *line, t_env *e, int i, int j)
{
	j++;
		ft_putendl(&line[i]);
	if (is_word(line, &i))
	{
		if (LAST == START || LAST >= 4) // >=4 --> IS_OP
		{
			ft_putendl("cmd?");
			PRESENT = CMD;
			ft_build_symbol_table(line, e, i, j);
		}
		else
		{
			if (LAST == CMD || LAST == ARG)
			{
				ft_putendl("arg");
				PRESENT = ARG;
				ft_build_symbol_table(line, e, i, j);
			}
			else
			{
				ft_putendl_fd("Syntax error 1", 2);
				return (1);
			}
		}
	}
	else
	{
		if (!line[i])
			return (0);
		if (LAST == START)
		{
			ft_putendl_fd("Syntax error 2", 2);
			return (1);
		}
		if ((PRESENT = is_op(line, &i)))
		{
			ft_putendl("is_op");
			i++;
			ft_build_symbol_table(line, e, i, j);
		}
		else
		{
			ft_putnbr(PRESENT);
			ft_putendl_fd("Syntax error 3", 2);
			return (1);
		}
	}
	ft_putendl("end");
	return (1);
}
