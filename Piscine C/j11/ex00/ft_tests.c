/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 04:33:27 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/11 04:07:45 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_list.h"

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

int		main(void)
{
	t_list *list;
	char a;
	char *b;

	a = 'Z';
	list = ft_create_elem(&a);
	b = (char *)list->data;
	ft_putchar(*b);
	return (0);
}
