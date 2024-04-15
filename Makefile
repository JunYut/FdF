# Compiler & Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g

# Directories
LIBFT_DIR = libft
SRC_DIR = src
OBJ_DIR = obj
INCL_DIR = includes

# Dependencies
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INCLUDE = $(INCL_DIR)/FdF.h
LIBFT = $(LIBFT_DIR)/libft.a
LIBFDF = libFdF.a
NAME = FdF

# Rules & Recipes
all: $(NAME)

$(NAME): $(LIBFDF) main.c
	$(CC) $(CFLAGS) main.c -o $(NAME) $(LIBFDF) -I$(INCL_DIR) -I$(LIBFT_DIR) -L. -L$(LIBFT_DIR) -lFdF -lmlx -lft -lm -framework OpenGL -framework AppKit

$(LIBFDF): $(LIBFT) $(OBJECTS)
	ar rc $(LIBFDF) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT) $(INCLUDE)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -I$(INCL_DIR) -I$(LIBFT_DIR) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFDF)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re