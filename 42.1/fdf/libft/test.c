#include "libft.h"

int	main(void)
{
	char	*str;
	char	**stab;

	str = ft_strdup("Bonjour my friend, my brother !");
	stab = ft_strsplit(str, ' ');
	return (0);
}
