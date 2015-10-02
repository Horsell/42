# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/01 18:07:41 by jpirsch           #+#    #+#              #
#    Updated: 2015/10/02 16:16:48 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../mod1
SRC			= 	main.cpp \
				env.cpp \
				draw.cpp
#SRC = $(addprefix sources/, $(shell ls sources | grep .cpp -F))
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I ../includes
CC			=	g++
RM			=	rm -f
LIB			=	-L ../glfw/src/ -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
OBJ			=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
#	g++ -o $(NAME) $(OBJ)
	$(CC) $(FLAGS) $(INCLUDES) $(SRC) $(LIB) -o $(NAME)

%.o: %.cpp
#	g++ -c $(FlAGS) $(SRC) -I ../includes
	$(CC) -O3 -o $@ -c $< $(FLAGS) $(INCLUDES)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : re fclean clean all
