#include "libft.h"

int	ft_getnbr(char *str)
{
	int	len;
	int	n;

	n = 0;
	len = ft_strlen(str);
	while (len)
	{
		n = (str[len] - 48) * len * 10;
		len--;
	}
	return (n);
}
