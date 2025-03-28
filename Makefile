CC = cc
CFLAGS = -Wall -Werror -Wextra

# Server and Client executable names
SERVER = server
CLIENT = client

# Source files
SERVER_SRC = server.c utils.c
CLIENT_SRC = client.c utils.c

# Object files
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# Printf library path
PRINTF_DIR = Printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(SERVER) $(CLIENT)

# Compile server
$(SERVER): $(SERVER_OBJ) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $@ $^

# Compile client
$(CLIENT): $(CLIENT_OBJ) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $@ $^

# Compile Printf library
$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

# Generic rule for object files
%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)
	make -C $(PRINTF_DIR) clean

# Clean everything including executables
fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make -C $(PRINTF_DIR) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
