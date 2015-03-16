#include "libft.h"
#include "ft_ls.h"

void	init_flags(t_flags *flags)
{
        flags->a = '0';
        flags->r_maj = '0';
        flags->l = '0';
        flags->r = '0';
        flags->t = '0';
}

void    check_options(char *av, t_flags *flags)
{
        int     i;

        i = 0;
        while (av && av[++i])
        {
                flags->a = ((av[i] == 'a') || flags->a == 1) ? 'a' : '0';
                flags->r_maj = ((av[i] == 'R') || flags->r_maj == 1) ? 'R' : '0';
                flags->l = ((av[i] == 'l') || flags->l == 1) ? 'l' : '0';
                flags->r = ((av[i] == 'r') || flags->r == 1) ? 'r' : '0';
                flags->t = ((av[i] == 't') || flags->t == 1) ? 't' : '0';
        }
}

char    **parse_args(char **av, t_flags *flags, int ac)
{
        int     nbfiles;
        int     i;
        int     j;
        char    **files;

        nbfiles = 0;
        i = 0;
        j = 0;
        init_flags(flags);
        while (av[++i] && ac--)
        {
                if (av[i][0] == '-')
                        check_options(av[i], flags);
                else
                        nbfiles++;
        }
        ac = i;
        i = 0;
        if ((files = (char **)(malloc(sizeof(char *) * (nbfiles + 1)))) == NULL)
                return (NULL);
        while (av[++i] && --ac)
        {
                if (av[i][0] != '-')
                        files[j++] = ft_strdup(av[i]);
        }
        files[j] = NULL;
        return (files);
}

void    display_flags(t_flags flags)
{
        ft_putchar(flags.a);
        ft_putchar('\n');
        ft_putchar(flags.r_maj);
        ft_putchar('\n');
        ft_putchar(flags.l);
        ft_putchar('\n');
        ft_putchar(flags.r);
        ft_putchar('\n');
        ft_putchar(flags.t);
        ft_putchar('\n');
}
