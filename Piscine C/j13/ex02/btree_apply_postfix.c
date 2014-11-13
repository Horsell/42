/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_postfix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 13:11:18 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/12 13:28:00 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_postfix(t_btree *root, void(*applyf)(void *))
{
	if (root->left_son)
		btree_apply_postfix(root->left_son, applyf);
	if (root->right_son)
		btree_apply_postfix(root->right_son, applyf);
	if (root)
		applyf(root);
}
