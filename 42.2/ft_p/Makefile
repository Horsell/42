# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 01:28:32 by jpirsch           #+#    #+#              #
#    Updated: 2015/10/01 01:54:55 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export FLAGS	= -Wall -Wextra -Werror
NAME			= ft_p
SRC_DIR			= ./sources
LIB_DIR			= ./libft

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
