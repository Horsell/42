/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 18:19:55 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/14 04:01:48 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_swap(int *a, int *b);
void	ft_putnbr(int n);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		ft_atoi(char *str);
#endif
