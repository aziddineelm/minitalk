CC = cc
FLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
SRC = utils.c

SRC_SERVER = server.c
SRC_CLIENT = client.c

ifeq ($(MAKECMDGOALS),bonus)
	SRC_SERVER = server_bonus.c
	SRC_CLIENT = client_bonus.c
endif

all : $(SERVER) $(CLIENT)

bonus : fclean $(SERVER) $(CLIENT)

$(SERVER) : $(SRC_SERVER) $(SRC)
	$(CC) $(FLAGS) $(SRC_SERVER) $(SRC) -o $(SERVER)

$(CLIENT) : $(SRC_CLIENT) $(SRC)
	$(CC) $(FLAGS) $(SRC_CLIENT) $(SRC) -o $(CLIENT)

fclean :
	rm -rf $(SERVER) $(CLIENT)

clean  :
	rm -rf *.o

re : fclean all

.PHONY : all fclean
