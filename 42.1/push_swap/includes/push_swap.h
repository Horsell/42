/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 03:38:05 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/16 06:51:13 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_pile
{
	int				val;
	struct s_pile	*next;
}					t_pile;

t_pile				*create_pile(int val);
t_pile				*push(t_pile *p, int val);
void				pop(t_pile **p);
void				display_pile(t_pile *p);
void				swap_pile(t_pile **p);
void				swap_two_pile(t_pile **a, t_pile **b);
t_pile				*push_swap(t_pile **a, t_pile *b);

#endif
