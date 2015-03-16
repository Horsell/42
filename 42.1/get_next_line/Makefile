# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/15 14:35:36 by jpirsch           #+#    #+#              #
#    Updated: 2015/03/16 07:23:53 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line
SRC	= get_next_line.c main.c
LIBDIR	= libft
OBJ	= $(SRC:.c=.o)
FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR)
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L $(LIBDIR) -lft

$(OBJ):
	gcc -c $(FLAGS) $(SRC) -I libft/includes/

clean:
	make -C $(LIBDIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -f $(NAME)

re: fclean all
