/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 00:39:41 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/08 19:15:56 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_BOOLEAN_H
# define	FT_BOOLEAN_H
# define	EVEN(nbr) (!(nbr % 2))
# define	EVEN_MSG "I have a pair number of arguments."
# define	ODD_MSG "I have an impair number of arguments."
# define	SUCCESS 0
# define	TRUE 1
# define	FALSE 0
typedef	int	t_bool;

void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);
#endif
