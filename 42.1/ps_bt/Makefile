# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/14 17:03:19 by jpirsch           #+#    #+#              #
#    Updated: 2015/06/14 17:08:29 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export FLAGS	=	-Wall -Wextra -Werror
SRC				=	./sources
LIB				=	./libft

all:
	make -C $(LIB)
	make -C $(SRC)

clean:
	make -C $(LIB) clean
	make -C $(SRC) clean

fclean: clean
	make -C $(LIB) fclean
	make -C $(SRC) fclean

re: fclean all
