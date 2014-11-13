/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 11:11:31 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/12 12:00:00 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree *node;

	node = NULL;
	node = malloc(sizeof(t_btree *));
	if (node)
	{
		node->item = item;
		node->left_son = NULL;
		node->right_son = NULL;
	}
	return (node);
}
