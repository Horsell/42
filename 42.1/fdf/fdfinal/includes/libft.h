/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:35:08 by jpirsch           #+#    #+#             */
/*   Updated: 2015/01/03 03:18:06 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# define ABS(x) ((x) < 0 ? -(x) : (x))

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
char	*ft_strdup(char *str);
void	ft_putnbr(int n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strsub(const char *s, unsigned int start, size_t len);
size_t	ft_strchr_len(char *s, char c);
size_t	ft_strlen(char *s);
char	*ft_strcpy(char *dst, const char *src);
void	*ft_bzero(void *t, size_t n);
char	*ft_strnew(size_t n);
int		ft_atoi(char *str);
char	*ft_itoa(int n);
char	*ft_strtrim_char(const char *s, char c);
char	**ft_strsplit(const char *s, char c);
size_t	ft_countwords(const char *s, char c);
void	*ft_tabmalloc(size_t size, size_t len);
#endif
