# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/14 00:47:31 by jpirsch           #+#    #+#              #
#    Updated: 2014/11/19 00:35:20 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get_next_line
SRC		=	get_next_line.c main.c
OBJ		=	$(SRC:.c=.o)
LIB		=	../libft/libft.a
LIB_DIR	=	./libft

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L libft/ -lft

$(OBJ):
	gcc -c $(FLAGS) $(SRC) -I libft

clean:
	make -C $(LIB_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all
