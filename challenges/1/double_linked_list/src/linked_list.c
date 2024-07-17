#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

linked_list_status stat;

linked_list_t *linked_list_init() {
  linked_list_t *list = (linked_list_t *)malloc(sizeof(linked_list_t));
  if (list == NULL) {
    stat = linked_list_out_of_memory;
    return NULL;
  }

  list->data = NULL;
  list->next = NULL;
  list->prev = NULL;

  stat = linked_list_success;
  return list;
}

void linked_list_free(linked_list_t *list) {
  if (list == NULL) {
    return;
  }
  linked_list_t *temp;

  for (; list != NULL; list = temp) {
    if (list->data != NULL) {
      free(list->data);
    }

    temp = list->next;
    free(list);
  }

  stat = linked_list_success;
}

void linked_list_insert_current(linked_list_t *list, char *d, int n) {
  assert(list != NULL);

  list->data = malloc(n);
  if (list->data == NULL) {
    stat = linked_list_out_of_memory;
    return;
  }

  strncpy(list->data, d, n);

  stat = linked_list_success;
}

void linked_list_insert_new(linked_list_t *list, char *d, int n) {
  int i;
  int list_length = linked_list_length(list);
  assert(list != NULL);

  linked_list_t *new = (linked_list_t *)malloc(sizeof(linked_list_t));
  memset(new, 0, sizeof(linked_list_t));

  linked_list_insert_current(new, d, n);
  if (stat != linked_list_success) {
    return;
  }

  // NOTE: starting with 1 here, as there is already a node when this function
  // is called
  for (i = 1; i < list_length; ++i) {
    list = list->next;
  }

  list->next = new;
  new->prev = list;

  stat = linked_list_success;
}

void linked_list_insert(linked_list_t *list, char *d, int n) {
  if (list == NULL) {
    stat = linked_list_null;
    return;
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

int linked_list_find(linked_list_t *list, char *str, int n) {
  int not_found = -1;
  int index;

  for (index = 1; list != NULL; list = list->next, ++index) {
    if (strncmp(list->data, str, n) == 0) {
      return index;
    }
  }

  return not_found;
}

void linked_list_delete(linked_list_t *list, int index) {
  if (index > linked_list_length(list)) {
    stat = linked_list_out_of_bounds;
    return;
  }

  for (; index > 1; list = list->next, --index)
    ;

  linked_list_t *temp = list->next;
  if (temp != NULL) {
    list->next = temp->next;
  }

  if (temp->next != NULL) {
    temp->next->prev = list;
  }

  free(temp->data);
  free(temp);

  stat = linked_list_success;
}

char *linked_list_strerror() {
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
    printf("Index: %-5dCurrent: %-20pPrev: %-20pNext: %-20pValue: %s\n", i, list, list->prev, list->next, list->data);
  }
}
