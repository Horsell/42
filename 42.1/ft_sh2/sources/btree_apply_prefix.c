/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 12:02:58 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/12 13:26:31 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void(*applyf)(void *))
{
	if (root)
		applyf(root);
	if (root->left_son)
		btree_apply_prefix(root->left_son, applyf);
	if (root->right_son)
		btree_apply_prefix(root->right_son, applyf);
}
