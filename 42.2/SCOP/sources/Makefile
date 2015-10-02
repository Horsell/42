# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/02 16:36:17 by jpirsch           #+#    #+#              #
#    Updated: 2015/10/02 16:46:05 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../scop
SRC			= 	main.c \
				env.c \
				draw.c
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I ../includes
CC			=	gcc
RM			=	rm -f
LIB			=	-L ../libft -lft -L ../glfw/src/ -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INCLUDES) $(SRC) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) -O3 -o $@ -c $< $(FLAGS) $(INCLUDES)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : re fclean clean all
