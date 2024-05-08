# Compiler and Flags
CC = gcc
# CFLAGS = -Wall -Wextra -Werror -pedantic -g
CFLAGS = -g

# Directories
MLX_DIR = minilibx-linux
LIBFT_DIR = libft
INCL_DIR = includes
SRC_DIR = src
OBJ_DIR = obj

# Source files
SRC = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Libraries
FDF = libfdf.a
MLX = libmlx.a
LIBFT = libft.a

# Executable
EXEC = main

# Rules and Recipes
all: $(EXEC)

$(EXEC): $(FDF) main.c
	$(CC) main.c -I$(INCL_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -L. -L$(MLX_DIR) -L$(LIBFT_DIR) -lfdf -lmlx -lft -lm -lX11 -lXext -o $(EXEC)

$(FDF): $(MLX) $(LIBFT) $(OBJ)
	ar rc $(FDF) $(OBJ)
	ranlib $(FDF)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCL_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re