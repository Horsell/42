# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 01:01:32 by jpirsch           #+#    #+#              #
#    Updated: 2014/09/09 23:21:06 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libstr.a

SRC = srcs/ft_putchar.c \
	  srcs/ft_putstr.c \
	  srcs/ft_strcmp.c \
	  srcs/ft_strlen.c \
	  srcs/ft_swap.c

OFILES = ft_putchar.o \
		 ft_putstr.o \
		 ft_strcmp.o \
		 ft_strlen.o \
		 ft_swap.o

FLAGS = -Wall -Werror -Wextra

HEADERS = /includes

all :
	gcc $(FLAGS) -c $(SRC) -I $(HEADERS)
	ar -rc $(NAME) $(OFILES)

.PHONY : clean
clean :
	rm -rf $(OFILES)

fclean : clean
	rm -rf $(NAME)

re : fclean all
