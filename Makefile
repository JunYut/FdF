# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g

# Directories
MLX_DIR = minilibx_macos

# Source files
SRC = $(wildcard *.c)

# Object files
OBJ = $(SRC:.c=.o)

# MinilibX
MLX = libmlx.a

# Executable
EXEC = main

# Rules and Recipes
all: $(EXEC)

$(EXEC): $(MLX) $(OBJ)
	$(CC) $(OBJ) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(EXEC)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

re: clean all

.PHONY: all clean re