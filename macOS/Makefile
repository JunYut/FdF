# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g

# Directories
MLX_DIR = minilibx_macos
LIBFT_DIR = libft
INCL_DIR = includes
OBJ_DIR = obj

# Source files
SRC = $(wildcard *.c)

# Object files
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Libraries
MLX = libmlx.a
LIBFT = libft.a

# Executable
EXEC = main

# Rules and Recipes
all: $(EXEC)

$(EXEC): $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -L$(MLX_DIR) -L$(LIBFT_DIR) -lmlx -lft -framework OpenGL -framework AppKit -o $(EXEC)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCL_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBFT_DIR)/$(LIBFT)
	rm -f $(MLX_DIR)/$(MLX)
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re