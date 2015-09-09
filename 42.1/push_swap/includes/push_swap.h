/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:35:08 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/05 18:33:19 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

void	push(t_list **pile, int val);
void	push_back(t_list **pile, int val);
void	ft_mydel(void *content, size_t content_size);
void	pop_back(t_list **pile);
void	pop(t_list **pile);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	rotate(t_list **pile);
void	rev_rotate(t_list **pile);
int	ft_findmin(t_list *a);
int	ft_getsize(t_list *a);
void	ft_getmin(t_list **a);
void	sort_pile(t_list **a, t_list **b);
#endif
