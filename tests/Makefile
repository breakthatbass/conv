# makefile for tests

CC=gcc
CFLAGS=-Wextra -pedantic -fsanitize=address
#leave out main.c
SRC_FILES=$(wildcard *_tests.c) ../src/conv.c ../src/helpers.c
NAME=tests

all: $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) -o $(NAME) $(SRC_FILES) $(CFLAGS)

clean:
	rm $(NAME)
