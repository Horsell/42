#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int	fd;
	char	*line;

	fd = open("get_next_line.c", O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
		ft_putendl(line);
	return (1);
}
