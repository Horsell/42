/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/12 11:30:25 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/12 17:15:27 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef	struct s_btree	t_btree;

struct		s_btree
{
	void	*item;
	t_btree *left_son;
	t_btree *right_son;
};


t_btree	*btree_create_node(void *item);

#endif
