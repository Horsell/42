#include "libft.h"

char	*ft_strnew(size_t n)
{
	char	*s;

	if (!n)
		return (NULL);
	s = malloc(sizeof(char*) * n);
	ft_bzero((void *)s, n);
	return (s);
}
