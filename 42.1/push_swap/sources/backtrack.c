/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 01:33:23 by jpirsch           #+#    #+#             */
/*   Updated: 2015/09/30 01:59:47 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_repeat(int *acts, int act, int last)
{
	int	ret;

	ret = 0;
	ret = (acts[last] == 0 && act == 1) ? 1 : 0;
	ret = (ret == 1 || (acts[last] == 1 && act == 0)) ? 1 : 0;
	ret = (ret == 1 || (acts[last] == 2 && act == 2)) ? 1 : 0;
	ret = (ret == 1 || (acts[last] == 3 && act == 3)) ? 1 : 0;
	ret = (ret == 1 || (acts[last] == 4 && act == 6)) ? 1 : 0;
	ret = (ret == 1 || (acts[last] == 6 && act == 4)) ? 1 : 0;
	ret = (ret == 1 || (acts[last] == 5 && act == 7)) ? 1 : 0;
	ret = (ret == 1 || (acts[last] == 7 && act == 5)) ? 1 : 0;
	ret = (ret == 1 || (acts[last] == 8 && act == 8)) ? 1 : 0;
	ret = (ret == 1 || (acts[last] == 9 && act == 10)) ? 1 : 0;
	ret = (ret == 1 || (acts[last] == 10 && act == 9)) ? 1 : 0;
	return (ret);
}

int			recursive_split_norme(t_backtrack *bk)
{
	if (is_sort(*bk->a) == ft_getsize(*bk->a) && ft_getsize(*bk->b) == 0\
			&& bk->depth <= bk->min_depth_solution)
	{
		bk->min_depth_solution = bk->depth;
		save_solution(bk);
		return (0);
	}
	if (bk->depth >= bk->min_depth_solution)
		return (-1);
	return (1);
}

int			recursive(t_backtrack *bk)
{
	int	i;
	int ret;

	i = 0;
	if ((ret = recursive_split_norme(bk)) < 1)
		return (ret);
	bk->depth++;
	while (i < 11)
	{
		if (bk->depth > 1 && check_repeat(bk->actions, i, bk->depth - 2))
			i++;
		else
		{
			if (apply_action(bk->a, bk->b, bk->e, i))
			{
				bk->actions[bk->depth - 1] = i;
				recursive(bk);
				rev_action(bk->a, bk->b, bk->e, i);
			}
			i++;
		}
	}
	bk->depth--;
	return (0);
}

t_backtrack	*init_backtrack(t_list **a, t_list **b, t_env *e, int depth)
{
	t_backtrack	*bk;
	int			i;

	if (!(bk = malloc(sizeof(t_backtrack))))
		return (NULL);
	bk->a = a;
	bk->b = b;
	bk->e = e;
	bk->depth = 0;
	bk->min_depth_solution = 8;
	i = 0;
	while (i < 8)
	{
		bk->actions[i] = -1;
		bk->best[i] = -1;
		i++;
	}
	return (bk);
}

int			backtrack(t_list **a, t_list **b, t_env *e, int depth)
{
	t_backtrack	*bk;

	bk = init_backtrack(a, b, e, depth);
	recursive(bk);
	if (bk->best[0] != -1)
	{
		e->v = 1;
		apply(a, b, e, bk->best);
		ft_putnbr(is_sort(*a)); // fair 'unapply" pour pouvoir tester si ca ne marche pas sans afficher
		ft_putstr(" ");
		ft_putnbr(ft_getsize(*a));
	}
	else
		sort_pile(a, b, e);
	free(bk);
	return (0);
}
