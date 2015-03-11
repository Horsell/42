/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 03:38:05 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/11 03:36:03 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int					*create_pile(int ac, char **av);
void				push(int *p, int val, int n);
void				pop(int *p, int n);
void				display_pile(int *p, int ac);
void				swap_pile(int *p, int ac);
void				swap_two_pile(int *a, int *b, int ac);
void				push_swap(int *a, int *b, int n);

#endif
