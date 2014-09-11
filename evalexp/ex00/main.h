#ifndef MAIN_H
# define MAIN_H

void	ft_do_op(char **str);
void	check_parenthesis(char **str);
int		eval_expr(char *str);
void	check_segment(char **str);

typedef struct	s_coord
{
	int		i;
	int		y;
}				t_coord;
#endif
