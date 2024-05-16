# !/bin/sh

echo "Checking FdF..."
norminette -R CheckForbiddenSourceHeader includes
norminette src
norminette main.c

echo

echo "Checking libft..."
norminette -R CheckForbiddenSourceHeader libft/c_libft.h
norminette libft/libft
norminette libft/ft_printf
norminette libft/get_next_line
