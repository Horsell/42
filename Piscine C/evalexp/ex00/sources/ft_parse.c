/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 11:22:05 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/14 21:39:21 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_parse.h"
#include "read.h"
#include "ft_operators.h"
#include <stdlib.h>

t_btree		*P_ops(char *str, int i)
{
	t_btree *tree;
	t_btree *tree1;

	if (str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		tree = mkleaf(str[i + 1]);
		//read;
		return (tree);
	}
	else if (str[i + 1] == '(')
	{
		//read;
		tree = E_ops(str, i);
		ft_expect(')');
		return (tree);
	}
	else if (str[i + 1] == '-')
	{
		//read;
		tree = P_ops(str, i);
		return (mknode(&ft_substract, tree, NULL));
	}
	else
		write(2, "Parse error\n", 12);
	return (tree);
}

t_btree		*T_ops(char *str, int i)
{
	t_btree *tree;
	t_btree *tree1;
	int		(*f_op)(int a, int b);

	tree = P_ops(str, i);
	while (str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '%')
	{
		f_op = ft_binary(str[i + 1]);
		//read;
		tree1 = P_ops(str, i);
		tree = mknode(0, f_op, tree, tree1);
	}
	return (tree);
}

t_btree		*E_ops(char *str, int i)
{
	t_btree *tree;
	t_btree *tree1;
	int		(*f_op)(int a, int b);

	tree = T_ops(str, i);
	while (str[i + 1] == '+' || str[i + 1] == '-')
	{
		f_op = ft_binary(str[i + 1]);
		//read;
		tree1 = T_ops(str, i);
		tree = mknode(f_op, tree, tree1);
	}
	return (tree);
}

t_btree		*exp_parser(char *str)
{
	t_btree *tree;

	tree = E_ops(str, 0);
	ft_expect('\0');
	return (tree);
}
