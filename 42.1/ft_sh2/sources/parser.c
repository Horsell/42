/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:36 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/12 14:28:32 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include "ft_btree.h"

void	new_op_node(t_env *e, int j)
{
	t_btree *test;
	void	*content;

	content = ;
	btree_create_node(content);
	(void)test;
}

int	new_cmd_node(t_env *e, int j)
{
	//new_node();
	while (PRESENT == ARG)
	{
	//	add_TOKEN_val_to_acav();
		j++;
	}
	return (j);
}

int	ft_build_exec_tree(t_env *e)
{
	int	j;

	j = 1;
/*	while (PRESENT)
	{
		if (PRESENT == CMD)
			j = new_cmd_node(e, j);
		if (PRESENT >= SEP)
			new_op_node(e, j);
		j++;
	}*/
	return (0);
}
