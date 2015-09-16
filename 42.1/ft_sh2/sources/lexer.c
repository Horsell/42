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
	{
		(*i)++;
		return (PIPE);
	}
	if (is_l_red(line, i))
	{
		(*i)++;
		return (L_RED);
	}
	if (is_r_red(line, i))
	{
		(*i)++;
		return (R_RED);
	}
	if (is_ll_red(line, i))
	{
		(*i) += 2;
		return (LL_RED);
	}
	if (is_rr_red(line, i))
	{
		(*i) += 2;
		return (RR_RED);
	}
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
		if (!ft_isprint(line[*i]) || !line[*i] || is_reserved_char(line[*i]))
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

void		add_to_tokens(t_env *e, int id, char *val, int i)
{
	int j;

	j = 1;
	while (PRESENT != 0)
		j++;
	PRESENT = id;
	if (val != NULL)
		ft_strncpy(PRESENT_val, val, i);
}

int		return_error(int code)
{
	ft_putstr_fd("Syntax error ", 2);
	ft_putnbr_fd(code, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int		state_word(char *line, t_env *e, int i, int j)
{
	int	tmp;

	tmp = i;
	is_word(line, &i);		// need to call it to increment i to end of word, damn norm param limit !
	if (LAST == START || LAST == SEP) // > SEP --> IS_OP
	{
		add_to_tokens(e, CMD, &line[tmp], i - tmp);
		ft_build_symbol_table(line, e, i, j);
	}
	else if (LAST > SEP)
	{
		add_to_tokens(e, FILEE, &line[tmp], i - tmp);
		ft_build_symbol_table(line, e, i, j);
	}
	else
	{
		if (LAST == CMD || LAST == ARG)
		{
			add_to_tokens(e, ARG, &line[tmp], i - tmp);
			ft_build_symbol_table(line, e, i, j);
		}
		else
			return (return_error(1));
	}
	return (0);
}


int		state_op(char *line, t_env *e, int i, int j)
{
	int	id;

	if (!line[i])
		return (0);
	if (LAST == START)
		return (return_error(2));
	if ((id = is_op(line, &i)))
	{
		if (LAST >= SEP)
			return (return_error(3));
		add_to_tokens(e, id, NULL, 0);
		ft_build_symbol_table(line, e, i, j);
	}
	else
		return (return_error(4));
	return (0);
}

int		ft_build_symbol_table(char *line, t_env *e, int i, int j)
{
	int	tmp;

	j++;
	tmp = i;
	if (is_word(line, &i))
		state_word(line, e, tmp, j);
	else
		state_op(line, e, i, j);
	return (1);
}
