#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 6

typedef struct	s_info
{
	int	i;
	int	status;
	int	ret;
	char	*s;
}		t_info;

int	get_next_line(int fd, char **line);
void	ft_putnbr(int n);

#endif
