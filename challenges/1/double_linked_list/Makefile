CC = cc
BIN_SINGLE = linked_list
BIN_DOUBLE = double_linked_list
TEST_SINGLE_BIN = test_linked_list
TEST_DOUBLE_BIN = test_double_linked_list

CFLAGS= -Wall -Wextra -g

SRCDIR = src
BINDIR = bin
TESTDIR = tests

all: build_single build_double run_single run_double

build_single:
	$(CC) $(CFLAGS) $(SRCDIR)/main_single.c $(SRCDIR)/linked_list.c -o $(BINDIR)/$(BIN_SINGLE)

run_single:
	./$(BINDIR)/$(BIN_SINGLE)

build_double:
	$(CC) $(CFLAGS) $(SRCDIR)/main_double.c $(SRCDIR)/double_linked_list.c -o $(BINDIR)/$(BIN_DOUBLE)

run_double:
	./$(BINDIR)/$(BIN_DOUBLE)

clean:
	rm -rf $(BINDIR)/*
	rm -rf $(TESTDIR)/$(TEST_SINGLE_BIN)
	rm -rf $(TESTDIR)/$(TEST_DOUBLE_BIN)

test:
	$(CC) $(CFLAGS) $(TESTDIR)/linked_list.c $(SRCDIR)/linked_list.c -o $(TESTDIR)/$(TEST_SINGLE_BIN)
	./$(TESTDIR)/$(TEST_SINGLE_BIN)
	$(CC) $(CFLAGS) $(TESTDIR)/double_linked_list.c $(SRCDIR)/double_linked_list.c -o $(TESTDIR)/$(TEST_DOUBLE_BIN)
	./$(TESTDIR)/$(TEST_DOUBLE_BIN)

.PHONY: build run clean test
