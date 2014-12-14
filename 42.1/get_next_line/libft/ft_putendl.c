#include "libft.h"

void	ft_putendl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	ft_putchar('\n');
}
