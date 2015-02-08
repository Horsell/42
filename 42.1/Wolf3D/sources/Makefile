# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 01:32:20 by jpirsch           #+#    #+#              #
#    Updated: 2015/01/20 17:37:02 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../wolf3d
SRC		= 	main.c \
			get_next_line.c \
			parse.c \
			ft_init_sdl.c \
			ft_init_renderer.c \
			ft_draw_sdl.c \
			sdl_env.c \
			event.c \
			draw.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L ../libft/ -lft \
		../libft/libSDL2-2.0.0.dylib ../libft/libSDL2.dylib

$(OBJ):
	gcc -c $(FLAGS) $(SRC) -I ../includes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
