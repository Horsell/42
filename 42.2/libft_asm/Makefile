# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 07:19:39 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 17:48:24 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a
CC = nasm -f macho64
AR = ar rc
RANLIB = ranlib
RM = rm
DIRSRC = src/
OBJ = $(SRC:.s=.o)
SRC = ft_puts.s \
	  ft_bzero.s \
	  ft_isalpha.s \
	  ft_isdigit.s \
	  ft_isalnum.s \
	  ft_isascii.s \
	  ft_isprint.s \
	  ft_toupper.s \
	  ft_tolower.s \
	  ft_strcat.s \
	  ft_strlen.s \
	  ft_memset.s \
	  ft_memcpy.s \
	  ft_strdup.s \
	  ft_cat.s \
	  ft_strcmp.s \
	  ft_strncmp.s \
	  ft_putstr.s 

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(RANLIB) $(NAME)

%.o: %.s
	@$(CC) $< -o $@

clean:
	@$(RM) -f $(OBJ)

fclean: clean
	@$(RM) -f $(NAME)

re: fclean all 

.PHONY: re fclean clean all
