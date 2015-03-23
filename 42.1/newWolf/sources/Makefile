# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 01:32:20 by jpirsch           #+#    #+#              #
#    Updated: 2015/03/23 12:50:29 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			parse.c \#
NAME	=	../wolf3d
SRC		= 	main.c \
			get_next_line.c \
			bmp_parser.c \
			ft_init_sdl.c \
			ft_draw_sdl.c \
			sdl_env.c \
			event.c \
			shoot.c \
			menu.c \
			draw.c
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
