# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/11 23:17:14 by jpirsch           #+#    #+#              #
#    Updated: 2014/09/11 23:22:07 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat

CFLAGS = -Wall -Werror -Wextra

SRC = ft_cat.c

OFILES = ft_cat.o

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)
