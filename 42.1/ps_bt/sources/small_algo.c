/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 15:24:43 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/29 20:42:51 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	one(t_list **a, t_list **b, t_env *e)
{
	if (*(int*)(*a)->content < *(int*)(*a)->next->next->content)
		swap_a(a, b, e);
	else
	{
		rotate_a(a, b, e);
		if (*(int*)(*a)->content > *(int*)(*a)->next->content)
			swap_a(a, b, e);
	}
}

void	sort_pileof3(t_list **a, t_list **b, t_env *e)
{
	if (!a)
		return ;
	if (is_sort(*a))
		return ;
	e->v = 1;
	if (*(int*)(*a)->content > *(int*)(*a)->next->content)
		one(a, b, e);
	else
	{
		if (*(int*)(*a)->content < *(int*)(*a)->next->next->content)
		{
			rev_rotate_a(a, b, e);
			swap_a(a, b, e);
		}
		else
			rev_rotate_a(a, b, e);
	}
}

int		apply_action(t_list **a, t_list **b, t_env *e, int action)
{
	(action == 0) ? swap_a(a, b, e) : 1;
	(action == 1) ? swap_b(a, b, e) : 1;
	(action == 2) ? rotate_a(a, b, e) : 1;
	(action == 3) ? rotate_b(a, b, e) : 1;
	(action == 4) ? rev_rotate_a(a, b, e) : 1;
	(action == 5) ? rev_rotate_b(a, b, e) : 1;
	(action == 6) ? ss(a, b, e) : 1;
	(action == 7) ? rr(a, b, e) : 1;
	(action == 8) ? rrr(a, b, e) : 1;
	return (1);
}

int		rev_action(t_list **a, t_list **b, t_env *e, int action)
{
	(action == 0) ? swap_a(a, b, e) : 1;
	(action == 1) ? swap_b(a, b, e) : 1;
	(action == 2) ? rev_rotate_a(a, b, e) : 1;
	(action == 3) ? rev_rotate_b(a, b, e) : 1;
	(action == 4) ? rotate_a(a, b, e) : 1;
	(action == 5) ? rotate_b(a, b, e) : 1;
	(action == 6) ? ss(a, b, e) : 1;
	(action == 7) ? rr(a, b, e) : 1;
	(action == 8) ? rrr(a, b, e) : 1;
	return (1);
}

void	display_action(int depth, int action)
{
	int	i;

	i = 0;
	while (i < depth)
	{
		ft_putstr("  ");
		i++;
	}
	ft_putnbr(depth);
	ft_putstr("  ");
	ft_putnbr(action);
	ft_putendl("");
}

void	disp(int *tab)
{
	int	i;

	i = 0;
	while (i < 7 && tab[i] != -1)
	{
		ft_putnbr(tab[i]);
		i++;
	}
	ft_putendl("");
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
	while (i < 7)
	{
		bk->best[i] = -1;
		i++;
	}
}

int		test(t_backtrack *bk)
{
	int	i;

	if (is_sort(*bk->a) == ft_getsize(*bk->a) && ft_getsize(*bk->b) == 0)
	{
		ft_putendl("found a solution.");
		disp(bk->actions);
		if (bk->depth < bk->min_depth_solution)
			save_solution(bk);
		return (0);
	}
	if (bk->depth >= bk->min_depth_solution)
		return (-1);
	i = 0;
	bk->depth++;
	while (i < 9)
	{
		apply_action(bk->a, bk->b, bk->e, i);
		bk->actions[bk->depth-1] = i;
		test(bk);
		rev_action(bk->a, bk->b, bk->e, i);
		i++;
	}
	bk->depth--;
	return (0);
}

int		backtrack(t_list **a, t_list **b, t_env *e, int depth)
{
	t_backtrack	*bk;
	int			i;

	bk = malloc(sizeof(t_backtrack));
	bk->a = a;
	bk->b = b;
	bk->e = e;
	bk->depth = 0;
	bk->min_depth_solution = ft_getsize(*a);
	if (ft_getsize(*a) > 7)
		bk->min_depth_solution = 7;
	i = 0;
	while (i < 7)
	{
		bk->actions[i] = -1;
		i++;
	}
	save_solution(bk);

	test(bk);

	disp(bk->best);
	return (0);
}
