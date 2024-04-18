# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g

# Directories
MLX_DIR = minilibx-linux
LIBFT_DIR = libft

# Source files
SRC = $(wildcard *.c)

# Object files
OBJ = $(SRC:.c=.o)

# Libraries
MLX = libmlx.a
LIBFT = libft.a

# Executable
EXEC = main

# Rules and Recipes
all: $(EXEC)

$(EXEC): $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -L$(MLX_DIR) -L$(LIBFT_DIR) -lmlx -lft -lX11 -o $(EXEC)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re