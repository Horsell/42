/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:35:08 by jpirsch           #+#    #+#             */
/*   Updated: 2014/12/15 14:41:00 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putendl(char *s);
char	*ft_strdup(char *str);
void	ft_putnbr(int n);
char	*ft_strsub(const char *s, unsigned int start, size_t len);
size_t	ft_strchr_len(char *s, char c);
size_t	ft_strlen(char *s);
void	*ft_bzero(void *t, size_t n);
char	*ft_strnew(size_t n);
#endif
