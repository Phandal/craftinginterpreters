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

typedef enum {
  linked_list_success,
  linked_list_out_of_memory,
} linked_list_status;

typedef void (*free_handler)(void *);

typedef struct linked_list {
  void *data;
  free_handler f;
  struct linked_list *next;
  int length;
} linked_list_t;

linked_list_status linked_list_init(linked_list_t *, free_handler);
linked_list_status linked_list_insert(linked_list_t *);
void linked_list_free(linked_list_t *);

int main(void) {
  linked_list_t outer;

  linked_list_init(&outer, free);

  linked_list_insert(&outer, (void *) "Hello", 5);

  // linked_list_find

  // linked_list_delete

  linked_list_free(
      &outer); // TODO: Need to find a better way to free the list recursively
}

linked_list_status linked_list_init(linked_list_t *list, free_handler free_h) {
  if ((list = malloc(sizeof(linked_list_t))) == NULL) {
    return linked_list_out_of_memory;
  }

  list->data = NULL;
  list->f = free_h;

  return linked_list_success;
}

linked_list_status linked_list_insert(linked_list_t *list, void *d, int n) {
  

void linked_list_free(linked_list_t *list) {
  if (list == NULL) {
    return;
  }
  free_handler f = list->f;

  for (;list->length > 0; ++list->data) {
    if (list->data != NULL) {
      f(list->data);
    }
  }
}
