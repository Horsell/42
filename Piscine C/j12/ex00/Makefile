# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/11 23:17:14 by jpirsch           #+#    #+#              #
#    Updated: 2014/09/11 23:36:36 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

CFLAGS = -Wall -Werror -Wextra

SRC = ft_display_file.c

OFILES = ft_cat.o

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)
