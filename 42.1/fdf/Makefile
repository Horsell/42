# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/14 00:47:31 by jpirsch           #+#    #+#              #
#    Updated: 2014/11/27 21:04:37 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME	=	fdf
SRC		=	get_next_line.c fdf.c main.c
OBJ		=	$(SRC:.c=.o)
LIB		=	../libft/libft.a
LIB_DIR	=	./libft

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L libft/ -lft -L/usr/X11/lib -lmlx -lXext \
		-lX11
$(OBJ):
	gcc -c $(FLAGS) $(SRC) -I libft

clean:
	make -C $(LIB_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all
