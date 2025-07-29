### Variablen ###

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = 	libftprintf.a
		

SRC = 	ft_printf.c \
		ft_hexadecimal.c \
		ft_number.c \
		ft_pointer.c \
		ft_putchar.c \
		ft_strcmp.c \
		ft_string.c \
		ft_unsigned.c

# convert from .c to .o
OBJ = $(SRC:%.c=%.o)

all: $(NAME) 

# Rule to compile
$(NAME): $(OBJ) 
	ar rcs $(NAME) $(OBJ)

re: fclean all

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

print_obj:
	@echo $(OBJ)
