UNAME_S := $(shell uname -s)

all:
ifeq ($(UNAME_S),Linux)
	make -C linux
endif
ifeq ($(UNAME_S),Darwin)
	make -C macOS
endif

run:
ifeq ($(UNAME_S),Linux)
	./linux/main
endif
ifeq ($(UNAME_S),Darwin)
	./macOS/main
endif

clean:
	make -C linux clean
	make -C macOS clean

fclean:
	make -C linux fclean
	make -C macOS fclean

.PHONY: all run clean fclean