# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 01:32:20 by jpirsch           #+#    #+#              #
#    Updated: 2015/03/22 05:33:57 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../wolf3d
SRC		= 	main.c 
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L ../libft/ -lft \
		../libft/libSDL2-2.0.0.dylib ../libft/libSDL2.dylib

$(OBJ):
	gcc -c -Ofast $(FLAGS) $(SRC) -I ../includes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
