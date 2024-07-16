#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef enum {
  linked_list_success,
  linked_list_out_of_memory,
  linked_list_null,
  linked_list_out_of_bounds,
} linked_list_status;

typedef struct linked_list {
  char *data;
  struct linked_list *next;
} linked_list_t;

linked_list_status linked_list_init(linked_list_t *);
void linked_list_free(linked_list_t *);
linked_list_status linked_list_insert(linked_list_t *, char *, int, int);
int linked_list_length(linked_list_t *);
char *linked_list_strerror(linked_list_status);
void linked_list_print(linked_list_t *);

#endif // LINKED_LIST_H
