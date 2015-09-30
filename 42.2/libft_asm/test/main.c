#include "../main.h"

int	main(void)
{
	char c;

	c = ft_strlen("lelela") + '0';
	ft_puts(&c);
	if (ft_isalpha('Z'))
		ft_puts("lalala");
	return (0);
}
