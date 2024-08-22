# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analunga <analunga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 22:08:20 by analunga          #+#    #+#              #
#    Updated: 2024/08/09 18:36:16 by analunga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SERVER_SRC = server.c
SERVER_BONUS_SRC = server_bonus.c
CLIENT_SRC = client.c
CLIENT_BONUS_SRC = client_bonus.c
UTILS_BONUS_SRC = utils_bonus.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)
UTILS_BONUS_OBJ = $(UTILS_BONUS_SRC:.c=.o)

SERVER = server
SERVER_BONUS = server_bonus
CLIENT = client
CLIENT_BONUS = client_bonus

# Rules
all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(UTILS_BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(UTILS_BONUS_OBJ)

$(SERVER_BONUS): $(SERVER_BONUS_OBJ) $(UTILS_BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_BONUS_OBJ) $(UTILS_BONUS_OBJ)

$(CLIENT): $(CLIENT_OBJ) $(UTILS_BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(UTILS_BONUS_OBJ)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ) $(UTILS_BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_BONUS_OBJ) $(UTILS_BONUS_OBJ)
	
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SERVER_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_OBJ) $(CLIENT_BONUS_OBJ) $(UTILS_BONUS_OBJ)

fclean: clean
	rm -f $(SERVER) $(SERVER_BONUS) $(CLIENT) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
