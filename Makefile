
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

SRC_DIR = src

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a


SRC_SERVER = 	$(SRC_DIR)/server.c
SRC_CLIENT =	$(SRC_DIR)/client.c
SRC_SERVER_BONUS = 	$(SRC_DIR)/server_bonus.c
SRC_CLIENT_BONUS =	$(SRC_DIR)/client_bonus.c

# convert from .c to .o
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)


all: $(LIBFT) $(PRINTF) $(NAME_SERVER) $(NAME_CLIENT) 

bonus: $(LIBFT) $(PRINTF) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS) 


# Rule to compile server and link only when necessary
$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(LIBFT) $(PRINTF)
$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) $(OBJ_SERVER_BONUS) $(LIBFT) $(PRINTF)


# Rule to compile client and link only when necessary
$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFT) $(PRINTF)
$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(OBJ_CLIENT_BONUS) $(LIBFT) $(PRINTF)


# Rule to compile .c files into .o files (Prevents unnecessary relinking)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compile ft_printf
$(PRINTF):
	make -C $(PRINTF_DIR)


re: fclean all

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)


.PHONY: clean fclean re all bonus

# .PHONY:
# Prevents conflicts – If a file named clean or all exists in your directory, make might think it’s already "built" and skip the rule.
# Ensures execution – make will always run the rule, even if a file with the same name exists.
# Improves clarity – It makes it clear which targets are just commands and not actual files.