/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:36 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/12 14:28:32 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		is_pipe(char *line, int *i)
{
	if (line[*i] == '|' && line[*i + 1])
	{
		if (ft_isspace(line[*i + 1]) || ft_isalnum(line[*i + 1]))
			return (1);
		else
			return (0);
	}
	else if (line[*i] == '|' && !(line[*i + 1]))
	{
		return (1); // c'est a une autre fonction de déterminer cette erreur
	}
	else
		return (0);
}

int		is_l_red(char *line, int *i)
{
	if (line[*i] == '<' && line[*i + 1])
	{
		if (ft_isspace(line[*i + 1]) || ft_isalnum(line[*i + 1]))
			return (1);
		else
			return (0);
	}
	else if (line[*i] == '<' && !(line[*i + 1]))
		return (1); // c'est a une autre fonction de déterminer cette erreur
	else
		return (0);
}

int		is_r_red(char *line, int *i)
{
	if (line[*i] == '>' && line[*i + 1])
	{
		if (ft_isspace(line[*i + 1]) || ft_isalnum(line[*i + 1]))
			return (1);
		else
			return (0);
	}
	else if (line[*i] == '>' && !(line[*i + 1]))
		return (1); // c'est a une autre fonction de déterminer cette erreur
	else
		return (0);
}

int		is_ll_red(char *line, int *i)
{
	if (line[*i] == '<' && line[*i + 1])
	{
		if (line[*i + 1] == '<' && line[*i + 2])
		{
			if (ft_isspace(line[*i + 2]) || ft_isalnum(line[*i + 2]))
				return (1);
			else
				return (0);
		}
		else if (line[*i + 1] == '<' && !(line[*i + 2]))
			return (1); // c'est a une autre fonction de déterminer cette erreur
		else
			return (0);
	}
	else
		return (0);
}

int		is_rr_red(char *line, int *i)
{
	if (line[*i] == '>' && line[*i + 1])
	{
		if (line[*i + 1] == '>' && line[*i + 2])
		{
			if (ft_isspace(line[*i + 2]) || ft_isalnum(line[*i + 2]))
				return (1);
			else
				return (0);
		}
		else if (line[*i + 1] == '>' && !(line[*i + 2]))
			return (1); // c'est a une autre fonction de déterminer cette erreur
		else
			return (0);
	}
	else
		return (0);
}
