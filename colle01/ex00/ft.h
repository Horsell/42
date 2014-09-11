/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 16:50:35 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/07 18:42:24 by mvercout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef	FT_H
# define	FT_H
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_swap(int *a, int *b);
void	ft_tab_fill(char **tab);
void	ft_display(char **tab);
#endif
