# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 01:32:20 by jpirsch           #+#    #+#              #
#    Updated: 2015/06/10 17:13:23 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../ft_sh2
SRC	= 	main.c \
		ft_execve.c \
		env.c \
		setenv.c \
		unsetenv.c \
		ft_cd.c \
		parse_command.c \
		lexer.c \
		lex_op.c \
		parser.c \
		btree_apply_prefix.c \
		btree_create_node.c \
		hashtable.c \
		termcaps.c \
		get_next_line.c
OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L ../libft/ -lft -ltermcap

%.o:%.c
	gcc -c $(FlAGS) $(SRC) -I ../includes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
