# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/14 17:10:37 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/28 19:28:46 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../push_swap
SRC		=	main.c \
			algo.c \
			algo2.c \
			op.c \
			op2.c \
			op3.c \
			small_algo.c \
			checks.c \
			pushnpop.c
OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L ../libft/ -lft

%.o:%.c
	gcc -c $(FlAGS) $(SRC) -I ../includes/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
