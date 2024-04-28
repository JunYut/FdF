# Compiler & Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

# Files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INCL = -I/usr/include/GL -I$(INC_DIR)

# Libraries
LIBCART = libcartesian.a

# Executable
EXEC = main

# Rules & Recipes
all: $(EXEC)

$(EXEC): $(LIBCART) main.c
	$(CC) $(CFLAGS) main.c -o $@ $(INCL) -L. -L/usr/local/lib -lcartesian -lGL -lGLU -lglut -lm

$(LIBCART): $(OBJ)
	ar rcs $@ $^
	ranlib $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

run:
	./$(EXEC)

clean:
	rm -f $(OBJ) $(LIBCART) $(EXEC)

re: clean all

.PHONY: all run clean re
