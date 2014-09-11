/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/04 17:29:48 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/04 22:16:43 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_sort_argv(int argc, char **argv)
{
	int		switch_done;
	int		i;
	char	*str_swap;

	switch_done = 1;
	while (switch_done == 1)
	{
		switch_done = 0;
		i = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				str_swap = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = str_swap;
				switch_done = 1;
			}
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	ft_sort_argv(argc, argv);
	while (i != argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
