/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 18:51:40 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/04 18:53:52 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_list	*arg_to_list(t_env *e)
{
	while (--ac >= 0)
	{
		if (!list)
			list = ft_lstnew(av[ac], sizeof(char) * ft_strlen(av[ac]));
		else
		{
			tmp = ft_lstnew(av[ac], sizeof(char) * ft_strlen(av[ac]));
			ft_lstadd(&list, tmp);
		}
	}
}

void	display_list(t_env *e)
{
	while (list)
	{
		ft_putendl_fd(list->content, fd);
		if (list->next)
			list = list->next;
		else
			break ;
	}
	return (list);
}
