#include "libft.h"
#include "get_next_line.h"

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar((n % 10) + '0');
}

char	*ft_strjoin2(char *s1, char *s2, int ret)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (s1 ? s1 : s2);
	if (!(str = ft_strnew(ft_strlen(s1) + ret)))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *str)
{
	char	*copy;
	int		i;

	copy = malloc(sizeof(char *) * ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (len == 0)
		return (ft_strdup(""));
	if (!(str = ft_strnew(len)))
		return (NULL);
	s += start;
	while (len--)
	{
		str[i] = s[i];
		if (str[i] == '\0')
			return (str);
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	split_tmp(t_info *f, char **line)
{
	char		*tmp;

	*line = ft_strsub(f->s, 0, f->i);
	tmp = f->s;
	f->s = ft_strdup(&f->s[f->i + 1]);
	free(tmp);
	return (1);
}

int	split_tmp2(t_info *f, char **line)
{
	char		*tmp;

	*line = ft_strdup("");
	tmp = f->s;
	f->s = ft_strdup(f->s + 1);
	free(tmp);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static t_info	f;
	char		buff[BUFF_SIZE];

	if (fd == -1)
		return (-1);
	if (!f.s)
		f.s = ft_strdup("");
	if (f.s[0] == '\n')
		return (split_tmp2(&f, line));
	else if (!(f.i = ft_strchr_len(f.s, '\n')))
	{
		while ((f.ret = read(fd, buff, BUFF_SIZE)))
		{
			buff[f.ret] = '\0';
			f.s = ft_strjoin2(f.s, buff, f.ret);
			if ((f.i = ft_strchr_len(f.s, '\n')))
				return (split_tmp(&f, line));
			else if (f.s[0] == '\n')
					return (split_tmp2(&f, line));
		}
	}
	else
		return (split_tmp(&f, line));
	return (f.ret);
}


