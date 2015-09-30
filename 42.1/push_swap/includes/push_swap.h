/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:35:08 by jpirsch           #+#    #+#             */
/*   Updated: 2015/10/01 00:14:15 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct	s_env
{
	int			opt_v;
	int			opt_c;
	int			v;
	int			size;
}				t_env;

typedef struct	s_backtrack
{
	t_list		**a;
	t_list		**b;
	t_env		*e;
	int			actions[8];
	int			best[8];
	int			depth;
	int			min_depth_solution;
}				t_backtrack;

void			display_pile(t_list *a, t_list *b, t_env *e);
void			push(t_list **pile, int val);
void			push_back(t_list **pile, int val);
void			ft_mydel(void *content, size_t content_size);
void			pop_back(t_list **pile);
void			pop(t_list **pile);
int				push_a(t_list **a, t_list **b, t_env *e);
int				push_b(t_list **a, t_list **b, t_env *e);
int				rotate_a(t_list **a, t_list **b, t_env *e);
int				rotate_b(t_list **a, t_list **b, t_env *e);
int				rev_rotate_a(t_list **a, t_list **b, t_env *e);
int				rev_rotate_b(t_list **a, t_list **b, t_env *e);
int				swap_a(t_list **a, t_list **b, t_env *e);
int				swap_b(t_list **a, t_list **b, t_env *e);
int				ss(t_list **a, t_list **b, t_env *e);
int				rr(t_list **a, t_list **b, t_env *e);
int				rrr(t_list **a, t_list **b, t_env *e);
int				ft_getsize(t_list *a);
void			ft_getmin(t_list **a, t_list **b, t_env *e);
void			sort_pile(t_list **a, t_list **b, t_env *e);
int				is_sort(t_list *a);
int				is_option(char *arg, t_env *e);
int				is_valid_int(char *arg);
int				check_args(int ac, char **av, t_env *e);
int				backtrack(t_list **a, t_list **b, t_env *e, int depth);
void			save_solution(t_backtrack *bk);
void			apply(t_list **a, t_list **b, t_env *e, int *tab);
int				rev_action(t_list **a, t_list **b, t_env *e, int action);
int				apply_action(t_list **a, t_list **b, t_env *e, int action);
#endif
