# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/02 16:33:18 by jpirsch           #+#    #+#              #
#    Updated: 2015/10/02 16:39:36 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export FLAGS	=	-Wall -Wextra -Werror
NAME			=	scop
SRC_DIR			=	./sources
LIB_DIR			=	./libft

all:
	make -C $(LIB_DIR)
	make -C $(SRC_DIR)

clean:
	make -C $(LIB_DIR) clean
	make -C $(SRC_DIR) clean

fclean: clean
	make -C $(LIB_DIR) fclean
	make -C $(SRC_DIR) fclean

re: fclean all

.PHONY: re fclean clean all
