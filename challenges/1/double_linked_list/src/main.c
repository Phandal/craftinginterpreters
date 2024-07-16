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

int main(void) {
  linked_list_status stat;
  linked_list_t outer;

  if ((stat = linked_list_init(&outer)) != linked_list_success) {
    fprintf(stderr, "init: %s\n", linked_list_strerror(stat));
    exit(stat);
  }

  if ((stat = linked_list_insert(&outer, "Hello", 6, 0)) !=
      linked_list_success) {
    fprintf(stderr, "insert: %s\n", linked_list_strerror(stat));
    exit(stat);
  }

  if ((stat = linked_list_insert(&outer, "World", 6, 1)) !=
      linked_list_success) {
    fprintf(stderr, "insert: %s\n", linked_list_strerror(stat));
    exit(stat);
  }

  linked_list_print(&outer);

  // linked_list_find

  // linked_list_delete

  linked_list_free(&outer);
}
