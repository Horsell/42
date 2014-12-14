#include "libft.h"

void	*ft_bzero(void *t, size_t n)
{
	while (n)
	{
		*(char*)t = '\0';
		t++;
		n--;
	}
	return (t);
}
