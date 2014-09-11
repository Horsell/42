/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 22:39:11 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/11 03:46:41 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = NULL;
	list = malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *list;

	list = ft_create_elem(data);
	if (list)
	{
		list->next = *begin_list;
		*begin_list = list;
	}
}

t_list		*ft_list_last(t_list **begin_list)
{
	t_list *list;

	list = *begin_list;
	if (list)
		while(list->next)
			list = list->next;
	return (list);
}

int		main(void)
{
	t_list *list;
	char a;
	char *b;
	char c;

	a = 'Z';
	c = 'y';
	list = ft_create_elem(&c);
	ft_list_push_front(&list, &a);
	ft_list_push_front(&list, &a);
	ft_list_push_front(&list, &a);
	list = ft_list_last(&list);
	b = list->data;
	ft_putchar(*b);
	return (0);
}
