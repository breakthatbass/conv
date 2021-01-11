
CC=gcc
CFLAGS=-W -Wall -Werror -Wextra -pedantic -fsanitize=address
PREFIX=/usr/local
SRC_FILES=$(wildcard src/*.c)
NAME=conv

all: $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) -o $(NAME) $(SRC_FILES) $(CFLAGS)

install: $(NAME)
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $< $(DESTDIR)$(PREFIX)/bin/$(NAME)

clean:
	rm $(NAME)
