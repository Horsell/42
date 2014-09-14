# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/13 19:48:58 by jpirsch           #+#    #+#              #
#    Updated: 2014/09/14 06:10:11 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c \
		  ft_strdup.c ft_putnbr.c ft_atoi.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ):
	gcc -c $(FLAGS) $(SRC) -I ../includes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
