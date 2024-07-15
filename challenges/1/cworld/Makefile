CC = cc
SRC = main.c
BIN = cworld

CFLAGS= -Wall -Wextra -pedantic

SRCDIR = src
BINDIR = bin

build: $(SRCDIR)/$(SRC)
	$(CC) $(CFLAGS) $(SRCDIR)/$(SRC) -o $(BINDIR)/$(BIN)

run:
	./$(BINDIR)/$(BIN)

clean:
	rm -rf $(BINDIR)/*

.PHONY: build run clean
