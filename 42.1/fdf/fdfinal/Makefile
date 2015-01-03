# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/13 15:55:33 by jpirsch           #+#    #+#              #
#    Updated: 2014/12/25 13:27:01 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export FLAGS	=	-Wall -Wextra -Werror
NAME			=	eval_expr
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
