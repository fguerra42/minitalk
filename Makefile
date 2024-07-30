NAME_CLIENT = client
NAME_SERVER = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRC = client.c
SERVER_SRC = server.c

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I $(LIBFT_DIR)/includes

PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = -I $(PRINTF_DIR)/includes

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(LIBFT_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(CLIENT_SRC) -o $(NAME_CLIENT) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf $(LIBFT_INC) $(PRINTF_INC)

$(NAME_SERVER): $(LIBFT_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(SERVER_SRC) -o $(NAME_SERVER) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf $(LIBFT_INC) $(PRINTF_INC)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re

