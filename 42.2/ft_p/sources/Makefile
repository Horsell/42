# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/01 01:58:20 by jpirsch           #+#    #+#              #
#    Updated: 2015/10/08 13:24:08 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		=	../server
CLIENT		=	../client
SERV_SRCS	= 	main.c \
				env.c \
				ft_execve.c \
				ft_cd.c \
				unsetenv.c \
				setenv.c \
				get_next_line.c
SERV_SRC	=	$(addprefix server/,$(SERV_SRCS))
CLIENT_SRCS	= 	main.c shell.c get_next_line.c
CLIENT_SRC	=	$(addprefix client/,$(CLIENT_SRCS))
INCLUDES	=	-I ../includes
CC			=	gcc
RM			=	rm -f
LIB			=	-L ../libft -lft
SERV_OBJ	=	$(SERV_SRC:.c=.o)
CLIENT_OBJ	=	$(CLIENT_SRC:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERV_OBJ)
	$(CC) $(FLAGS) $(INCLUDES) $(SERV_SRC) $(LIB) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(INCLUDES) $(CLIENT_SRC) $(LIB) -o $(CLIENT)

%.o:%.c
#	$(CC) -O3 -o $(SERV_OBJ) -c $(SERV_SRC) $(FLAGS) $(INCLUDES)
	$(CC) -O3 -c $(SERV_SRC) $(FLAGS) $(INCLUDES)
	$(CC) -O3 -c $(CLIENT_SRC) $(FLAGS) $(INCLUDES)

clean:
	$(RM) $(CLIENT_OBJ) $(SERV_OBJ)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY : re fclean clean all
