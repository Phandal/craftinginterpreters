CC = cc
BIN = linked_list
TESTBIN = test_linked_list

CFLAGS= -Wall -Wextra -g

SRCDIR = src
BINDIR = bin
TESTDIR = tests

build:
	$(CC) $(CFLAGS) $(SRCDIR)/*.c -o $(BINDIR)/$(BIN)

run:
	./$(BINDIR)/$(BIN)

clean:
	rm -rf $(BINDIR)/*
	rm -rf $(TESTDIR)/$(TESTBIN)

test:
	$(CC) $(CFLAGS) $(TESTDIR)/*.c $(SRCDIR)/linked_list.c -o $(TESTDIR)/$(TESTBIN)
	./$(TESTDIR)/$(TESTBIN)

.PHONY: build run clean test
