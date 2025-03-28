CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_put_hex.c
OBJ = $(SRC:.c=.o)
NAME= libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
