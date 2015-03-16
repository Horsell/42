/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 01:28:45 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/16 07:01:58 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_pile	*create_pile(int val)
{
	t_pile *p;

	p = NULL;
	if ((p = malloc(sizeof(t_pile))))
	{
		p->val = val;
		p->next = NULL;
	}
	return (p);
}

t_pile	*push(t_pile *p, int val)
{
	t_pile *new;
	t_pile *tmp;

	new = NULL;
	tmp = NULL;
	if (p == NULL)
		 p = create_pile(val);
	else
	{
		new = create_pile(val);
		tmp = p;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (p);
}

void	pop(t_pile **p)
{
	t_pile *tmp;

	if (!*p)
		return ;
	tmp = *p;
	*p = (*p)->next;
	free(tmp);
}

void	display_pile(t_pile *p)
{
	t_pile *tmp;

	if (!p)
		return ;
	tmp = p;
	while (tmp->next)
	{
		ft_putnbr(tmp->val);
		tmp = tmp->next;
	}
	ft_putnbr(tmp->val);
}

void	swap_pile(t_pile **p)
{
	int tmp;

	if (*p && (*p)->next)
	{
		tmp = (*p)->val;
		(*p)->val = (*p)->next->val;
		(*p)->next->val = tmp;
	}
}
