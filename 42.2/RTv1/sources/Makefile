# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 01:32:20 by jpirsch           #+#    #+#              #
#    Updated: 2015/05/09 16:10:46 by sven             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../RTv1
SRC		= 	main.c \
			get_next_line.c \
			parse.c \
			ft_init_sdl.c \
			ft_draw_sdl.c \
			sdl_env.c \
			event.c \
			ray.c \
			draw.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L ../libft/ -lft -lSDL2

//$(OBJ):
%.o: %.c
	gcc -c -Ofast $(SRC) -I ../includes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
