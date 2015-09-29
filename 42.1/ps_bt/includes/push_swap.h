/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:35:08 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/29 20:33:15 by jpirsch          ###   ########.fr       */
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
}				t_env;

typedef struct	s_backtrack
{
	t_list		**a;
	t_list		**b;
	t_env		*e;
	int			actions[7];
	int			best[7];
	int			depth;
	int			min_depth_solution;
}				t_backtrack;

void			display_pile(t_list *a, t_list *b, t_env *e);
void			push(t_list **pile, int val);
void			push_back(t_list **pile, int val);
void			ft_mydel(void *content, size_t content_size);
void			pop_back(t_list **pile);
void			pop(t_list **pile);
void			push_a(t_list **a, t_list **b, t_env *e);
void			push_b(t_list **a, t_list **b, t_env *e);
void			rotate_a(t_list **a, t_list **b, t_env *e);
void			rotate_b(t_list **a, t_list **b, t_env *e);
void			rev_rotate_a(t_list **a, t_list **b, t_env *e);
void			rev_rotate_b(t_list **a, t_list **b, t_env *e);
void			swap_a(t_list **a, t_list **b, t_env *e);
void			swap_b(t_list **a, t_list **b, t_env *e);
void			ss(t_list **a, t_list **b, t_env *e);
void			rr(t_list **a, t_list **b, t_env *e);
void			rrr(t_list **a, t_list **b, t_env *e);
int				ft_findmin(t_list *a);
int				ft_getsize(t_list *a);
void			ft_getmin(t_list **a, t_list **b, t_env *e);
void			sort_pile(t_list **a, t_list **b, t_env *e);
void			sort_pileof3(t_list **a, t_list **b, t_env *e);
int				is_sort(t_list *a);
int				is_option(char *arg, t_env *e);
int				is_valid_int(char *arg);
int				check_args(int ac, char **av, t_env *e);
int				backtrack(t_list **a, t_list **b, t_env *e, int depth);
#endif
