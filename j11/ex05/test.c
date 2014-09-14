/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 22:39:11 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/11 06:35:17 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
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

void	*ft_list_push_back(t_list **begin_list, void *data)
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

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list *list;
	int i;

	list = ft_create_elem(&av);
	i = 1;
	while (i < ac);
	{
		list = ft_list_push_back(&list, av++);
		ft_putstr((char *)list->data);
		list = list->next;
		i++;
	}

	return (list);
}

int		main(int ac, char **av)
{
	t_list *list;
	//char *c;

	list = ft_list_push_params(ac, av);
	ft_putstr((char *)list->data);
	if (list)
	{
		while (list->next)
		{
			//c = (char *)list->data;
			ft_putchar('n');
			ft_putstr((char *)list->data);
			list = list->next;
		}
	}
	return (0);
}
