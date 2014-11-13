/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 05:27:47 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/14 10:50:19 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "main.h"
#include <stdlib.h>

t_coord		*init_seg(int i, int y)
{
	t_coord *seg;

	seg = malloc(sizeof(t_coord *));
	if (seg)
	{
		seg->x1 = i;
		seg->x2 = y;
	}
	return (seg);
}

t_btree		*btree_create_node(int value, int(*f_op)(int, int))
{
	t_btree *node;

	node = malloc(sizeof(t_btree *));
	if (node)
	{
		node->value		=	value;
		node->f_op		=	f_op;
		node->left_son	=	NULL;
		node->right_son	=	NULL;
	}
	return (node);
}

t_btree		*btree_add_left_node(t_btree **daddy, int value, int(*f_op)(int, int))
{
	t_btree *dnode;
	t_btree *node;

	node = btree_create_node(value, f_op);
	dnode = *daddy;
	if (dnode && node)
		dnode->left_son	= node;
	return (node);
}

int			ft_is_op(char c)
{
	if (c == '*')
		return (1);
	if (c == '/')
		return (2);
	if (c == '%')
		return (3);
	if (c == '+')
		return (4);
	if (c == '-')
		return (5);
	else
		return (0);
}

t_coord		*check_parenthesis(char *str)
{
	t_coord		*seg;
	int			i;

	i = 0;
	seg = init_seg(0, 0);
	while (str[i])
	{
		if (str[i] == '(')
			seg->x1 = i;
		if (str[i] == ')')
			break ;
		i++;
	}
	seg->x2 = i;
	return (seg);
}

t_btree		*P_ops(char *str, int i)
{
	t_btree *tree;
	t_btree *tree1;
	op;

	if (str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		tree = mkleaf(str, i + 1);
		read;
		return (tree);
	}
	else if (str[i + 1] == '(')
	{
		read;
		tree = E_ops(str, i);
		expect(')');
		return (tree);
	}
	else if (str[i + 1] == '-')
	{
		read;
		tree = P_ops(str, i);
		return (mknode(unary('-'), tree));
	}
	else
		write(2, "Parse error\n", 12);
	return (tree);
}

t_btree		*T_ops(char *str, int i)
{
	t_btree *tree;
	t_btree *tree1;
	op;

	tree = P_ops(str);
	while (str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '%')
	{
		op = binary(str);
		read;
		tree1 = P_ops(str);
		tree = mknode(op, tree, tree1);
	}
	return (tree);
}

t_btree		*E_ops(char *str, int i)
{
	t_btree *tree;
	t_btree *tree1;
	op;

	tree = T_ops(str, i);
	while (str[i + 1] == '+' || str[i + 1] == '-')
	{
		op = binary(str, i);
		read;
		tree1 = T_ops(str, i);
		tree = mknode(op, tree, tree1);
	}
	return (tree);
}

t_btree		*exp_parser(char *str)
{
	t_btree *tree;

	tree = E_ops(str, 0);
	expect('\0');
	return (tree);
}

int			main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(btree_infix_traversal(exp_parser(av[1])));
		ft_putchar('\n');
	}
	return (0);
}
