#include "libft.h"
#include "ft_ls.h"

int	main(int ac, char **av)
{
	t_flags			flags;
	char			**files;
	int				*fd;
	DIR				*dir;
	struct dirent	*dp;

	files = parse_args(av, &flags, ac);
	dir = opendir(".");
	while ((dp = readdir(dir)) != NULL)
	{
		ft_putendl(dp->d_name);
	}
	return (1);
}
