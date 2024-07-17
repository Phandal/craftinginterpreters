/*
 * Implement a doubly linked list of heap allocated strings
 * author: Phandal <bfeld.111@gmai.com>
 * date: 07/15/2024
 */

/* TODO
   1. Think about if you should add insert and append or just insert?
      Does insert need to take a position?
   2. Look into some sort of tdd with tests.
      This also means moving the list stuff to its own lib.
  */

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

extern linked_list_status stat;

int main(void) {
  linked_list_t *outer = linked_list_init();
  if (stat != linked_list_success) {
    fprintf(stderr, "init: %s\n", linked_list_strerror());
    exit(stat);
  }

  linked_list_insert(outer, "hello", 6);
  if (stat != linked_list_success) {
    fprintf(stderr, "insert: %s\n", linked_list_strerror());
    exit(stat);
  }

  linked_list_insert(outer, "world", 6);
  if (stat != linked_list_success) {
    fprintf(stderr, "insert: %s\n", linked_list_strerror());
    exit(stat);
  }
  printf("Linked List Original:\n");
  linked_list_print(outer);

  linked_list_delete(outer, 1);
  if (stat != linked_list_success) {
    fprintf(stderr, "delete: %s\n", linked_list_strerror());
    exit(stat);
  }
  
  printf("Linked List After Delete:\n");
  linked_list_print(outer);

  linked_list_free(outer);
}
