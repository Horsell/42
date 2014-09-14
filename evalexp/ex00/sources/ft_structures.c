/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 11:14:20 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/14 21:35:57 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_structures.h"

t_btree		*mknode(int(*f_op)(int, int), t_btree *left_son, t_btree *right_son)
{
	t_btree *node;

	node = malloc(sizeof(t_btree *));
	if (node)
	{
		node->value		=	0;
		node->f_op		=	f_op;
		node->left_son	=	left_son;
		node->right_son	=	right_son;
	}
	return (node);
}

t_btree		*mkleaf(int value)
{
	t_btree *node;

	node = malloc(sizeof(t_btree *));
	if (node)
	{
		node->value		= value;
		node->f_op		= NULL;
		node->left_son	= NULL;
		node->right_son	= NULL;
	}
	return (node);
}

void	btree_infix_traversal(t_btree *root)
{
	t_btree *left;
	t_btree *right;

	left = malloc(sizeof(t_btree *));
	left = root->left_son;
	right = malloc(sizeof(t_btree *));
	right = root->right_son;
	if (root->left_son)
		btree_infix_traversal(root->left_son);
	if (root)
		root->f_op(left->value, right->value);
	if (root->right_son)
		btree_infix_traversal(root->right_son);
}
