CC = cc

CFLAGS = -Wall -Werror -Wextra

SERVER = server

CLIENT = client

SERVER_SRC = server.c utils.c

CLIENT_SRC = client.c utils.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

PRINTF_DIR = Printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT): $(CLIENT_OBJ) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $@ $^

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
