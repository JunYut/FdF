# !/bin/sh

if [ $# -eq 0 ] || [ $# -gt 2 ]; then
	echo "Usage: sh $0 <file.fdf> <l/v>"
	exit 1
fi

make

if [ $# -eq 2 ]; then
	if [ "$2" = "l" ]; then
		leaks -atExit -- ./FdF $1
		exit 0
	elif [ "$2" = "v" ]; then
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./FdF $1
		exit 0
	else
		echo "Usage: sh $0 <file.fdf> <l/v>"
		exit 1
	fi
else
	./FdF $1
	exit 0
fi