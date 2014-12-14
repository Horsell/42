NAME	=	libft.a
SRC	=	ft_strlen.c \
		ft_strchr_len.c \
		ft_putchar.c \
		ft_putendl.c \
		ft_strnew.c \
		ft_bzero.c
OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
