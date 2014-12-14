#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putendl(char *s);
size_t	ft_strchr_len(char *s, char c);
size_t	ft_strlen(char *s);	
void	*ft_bzero(void *t, size_t n);
char	*ft_strnew(size_t n);

#endif
