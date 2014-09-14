/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 22:39:11 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/11 02:20:45 by jpirsch          ###   ########.fr       */
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

void	*ft_list_push_back(t_list **begin_list,void *data)
{
	t_list *list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
	return (*begin_list);
}

int		main(void)
{
	t_list *list;
	char a;
	char *b;
	char c;
	char *d;

	a = 'Z';
	c = 'y';
	list = ft_create_elem(&a);
	b = (char *)list->data;
	ft_putchar(*b);
	ft_list_push_back(&list, &c);
	while (list->next)
		list = list->next;
	d = (char *)list->data;
	ft_putchar(*d);
	return (0);
}
