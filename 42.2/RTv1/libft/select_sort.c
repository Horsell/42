#include "libft.h"

static int	ft_select_min(int *tab, int i, size_t size)
{
	int k;

	k = i;
	while (i < size)
	{
		if (tab[i] < tab[k])
			k = i;
		i++;
	}
	return (k);
}

void		select_sort(int *tab, size_t size)
{
	int	i;
	int	k;

	i = 0;
	while (i < size)
	{
		k = ft_select_min(tab, i, size);
		ft_swap(&tab[k], &tab[i]);
		i++;
	}
}
