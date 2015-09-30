/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 01:26:59 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/30 16:08:28 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		apply_action(t_list **a, t_list **b, t_env *e, int action)
{
	int	ret;

	ret = 1;
	ret = (action == 0) ? push_a(a, b, e) : ret;
	ret = (action == 1) ? push_b(a, b, e) : ret;
	ret = (action == 2) ? swap_a(a, b, e) : ret;
	ret = (action == 3) ? swap_b(a, b, e) : ret;
	ret = (action == 4) ? rotate_a(a, b, e) : ret;
	ret = (action == 5) ? rotate_b(a, b, e) : ret;
	ret = (action == 6) ? rev_rotate_a(a, b, e) : ret;
	ret = (action == 7) ? rev_rotate_b(a, b, e) : ret;
	ret = (action == 8) ? ss(a, b, e) : ret;
	ret = (action == 9) ? rr(a, b, e) : ret;
	ret = (action == 10) ? rrr(a, b, e) : ret;
	return (ret);
}

int		rev_action(t_list **a, t_list **b, t_env *e, int action)
{
	int	ret;

	ret = 1;
	(action == 0) ? push_b(a, b, e) : 1;
	(action == 1) ? push_a(a, b, e) : 1;
	(action == 2) ? swap_a(a, b, e) : 1;
	(action == 3) ? swap_b(a, b, e) : 1;
	(action == 4) ? rev_rotate_a(a, b, e) : 1;
	(action == 5) ? rev_rotate_b(a, b, e) : 1;
	(action == 6) ? rotate_a(a, b, e) : 1;
	(action == 7) ? rotate_b(a, b, e) : 1;
	(action == 8) ? ss(a, b, e) : 1;
	(action == 9) ? rr(a, b, e) : 1;
	(action == 10) ? rrr(a, b, e) : 1;
	return (ret);
}

void	apply(t_list **a, t_list **b, t_env *e, int *tab)
{
	int	i;

	i = 0;
	while (i < 8 && tab[i] != -1)
	{
		apply_action(a, b, e, tab[i]);
		i++;
	}
}

void	save_solution(t_backtrack *bk)
{
	int	i;

	i = 0;
	while (i < bk->min_depth_solution)
	{
		bk->best[i] = bk->actions[i];
		i++;
	}
	while (i < 8)
	{
		bk->best[i] = -1;
		i++;
	}
}
