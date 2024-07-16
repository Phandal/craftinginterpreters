#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

linked_list_status linked_list_init(linked_list_t *list) {
  if (list == NULL) {
    return linked_list_null;
  }

  list->data = NULL;
  list->next = NULL;

  return linked_list_success;
}

void linked_list_free(linked_list_t *list) {
  if (list == NULL) {
    return;
  }

  for (; list != NULL; list = list->next) {
    if (list->data != NULL) {
      free(list->data);
    }
  }
}

linked_list_status linked_list_insert_current(linked_list_t *list, char *d,
                                              int n) {
  assert(list != NULL);

  list->data = malloc(n);
  if (list->data == NULL) {
    return linked_list_out_of_memory;
  }

  strncpy(list->data, d, n);

  return linked_list_success;
}

linked_list_status linked_list_insert_new(linked_list_t *list, char *d, int n) {
  linked_list_status stat;
  assert(list != NULL);

  linked_list_t *temp = (linked_list_t *)malloc(sizeof(linked_list_t));
  memset(temp, 0, sizeof(linked_list_t));

  if ((stat = linked_list_insert_current(temp, d, n)) != linked_list_success) {
    return stat;
  }

  temp->next = list->next;
  list->next = temp;

  return linked_list_success;
}

linked_list_status linked_list_insert(linked_list_t *list, char *d, int n,
                                      int p) {
  if (list == NULL) {
    return linked_list_null;
  }

  if (p > linked_list_length(list)) {
    return linked_list_out_of_bounds;
  }

  if (list->data == NULL) {
    return linked_list_insert_current(list, d, n);
  } else {
    return linked_list_insert_new(list, d, n);
  }
}

int linked_list_length(linked_list_t *list) {
  if (list->data == NULL) {
    return 0;
  }

  int i;
  for (i = 0; list != NULL; list = list->next) {
    i += 1;
  }
  return i;
}

char *linked_list_strerror(linked_list_status stat) {
  switch (stat) {
  case linked_list_success:
    return "success";
  case linked_list_out_of_memory:
    return "out of memory";
  case linked_list_null:
    return "pointer was null";
  case linked_list_out_of_bounds:
    return "out of bounds";
  default:
    return "unexpected error";
  }
}

void linked_list_print(linked_list_t *list) {
  int i;

  for (i = 0; list != NULL; list = list->next, ++i) {
    printf("\tIndex: %5d\tValue: %s\n", i, list->data);
  }
}
