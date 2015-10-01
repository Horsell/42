NAME = scop
CC = gcc
RM = rm -f
LIB =  -L libft/ -lft
SDL = -L ./glfw/src/ -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
CFLAGS = -Wall -Wextra -Werror -I ./includes -I ./libft/includes/ -I ./glfw/include/
SRC = $(addprefix sources/, $(shell ls sources | grep .c -F))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(SRC) $(LIB) $(SDL) -o $(NAME)

%.o: %.c
	$(CC) -O3 -o $@ -c $< $(CFLAGS)

clean:
	make -C libft clean
	$(RM) $(OBJ)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
