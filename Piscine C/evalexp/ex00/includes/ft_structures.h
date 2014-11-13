/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 11:31:01 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/14 21:35:13 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTURES_H
# define FT_STRUCTURES_H

typedef struct s_btree	t_btree;

struct			s_btree
{
	int		value;
	int		(*f_op)(int a, int b);
	t_btree *left_son;
	t_btree *right_son;
};

void		btree_infix_traversal(t_btree *root);
t_btree		*mknode(int(*f_op)(int, int), t_btree *left_son, t_btree *right_son);
t_btree		*mkleaf(int value);
#endif
