# Operating System
OS = $(shell uname -s)

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g

# Directories
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

# OS-specific linking
ifeq ($(OS), Darwin)
MLX_DIR = minilibx_macos
MLX_LINK = -framework OpenGL -framework AppKit
else ifeq ($(OS), Linux)
MLX_DIR = minilibx-linux
MLX_LINK = -lX11 -lXext
endif

$(EXEC): $(FDF) $(MLX) $(LIBFT) main.c
	$(CC) main.c -I$(INCL_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -L. -L$(MLX_DIR) -L$(LIBFT_DIR) -lfdf -lmlx -lft -lm $(MLX_LINK) -o $(EXEC)

$(FDF): $(OBJ)
	ar rc $(FDF) $(OBJ)
	ranlib $(FDF)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCL_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBFT_DIR)/$(LIBFT)
	rm -f $(MLX_DIR)/$(MLX)
	rm -f $(FDF)
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re