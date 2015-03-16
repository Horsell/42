# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/15 14:36:12 by jpirsch           #+#    #+#              #
#    Updated: 2014/12/15 17:18:39 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRC		=	ft_strlen.c \
			ft_putnbr.c \
			ft_strdup.c \
			ft_strsub.c \
			ft_strchr_len.c \
			ft_putchar.c \
			ft_putendl.c \
			ft_strnew.c \
			ft_bzero.c
FLAGS	=	-Wall -Wextra -Werror
OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	    @$ gcc -o $@ -c $< $(FLAGS) -I includes/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
