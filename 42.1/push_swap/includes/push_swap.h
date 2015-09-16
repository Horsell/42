/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:35:08 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/16 05:05:57 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

void	display_pile(t_list *a, t_list *b);
void	push(t_list **pile, int val);
void	push_back(t_list **pile, int val);
void	ft_mydel(void *content, size_t content_size);
void	pop_back(t_list **pile);
void	pop(t_list **pile);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rev_rotate_a(t_list **a);
void	rev_rotate_b(t_list **b);
void	swap_a(t_list **a);
int		ft_findmin(t_list *a);
int		ft_getsize(t_list *a);
void	ft_getmin(t_list **a);
void	sort_pile(t_list **a, t_list **b);
void	sort_pileof3(t_list **a, t_list **b);
int		is_sort(t_list *a);
#endif
