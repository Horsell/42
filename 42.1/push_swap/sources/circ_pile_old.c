/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 01:28:45 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/11 02:36:36 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_pile	*create_pile(int val)
{
	t_pile *p;

	p = NULL;
	if ((p = malloc(sizeof(t_pile) * 1)))
	{
		p->val = val;
		p->pred = p;
		p->next = p;
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
	{
		 p = create_pile(val);
		 p->first = 1;
		 return (p);
	}
	else
	{
		new = create_pile(val);
		new->first = 0;
		tmp = p->next;//tmp pointe vers le 1er
		tmp->pred = new;//le premier pointe vers new
		p->next = new;// le precedent pointe vers new
		new->next = tmp;//new pointe vers le 1er
		new->pred = p;//new pointe vers le precedent
	}
	return (new);
}

void	pop(t_pile **p)
{
	t_pile **tmp;

	tmp = p;
	*p = (*p)->pred;
	(*p)->next = (*tmp)->next;
	free(*tmp);
//	t_pile *tmp2;

	/*if (p != NULL)
	{
		tmp1 = (*p)->pred;
		tmp1->next = (*p)->next;
		tmp2 = *p;
		*p = (*p)->next;
		p->pred = tmp;
		free(tmp2);
	}
	tmp = p;
	*p = (*p)->pred;
	(*p)->next = (*p)->next->next;
	*p = (*p)->next;
	(*p)->pred = *tmp;
	*p = (*tmp)->pred;
	free(*tmp);*/
}

void	display_pile(t_pile *p)
{
	if (p != NULL)
	{
		while (p->first != 1)
		{
			ft_putnbr(p->val);
			p = p->pred;
		}
		ft_putnbr(p->val);
	}
}

void	swap_pile(t_pile **p)
{
	t_pile **tmp;

	if (p != NULL && (*p)->pred != NULL)
	{
		tmp = p;
		p = &((*p)->pred);
		ft_swap((void*)p, (void*)tmp);
		*p = (*p)->next;
	}
}
