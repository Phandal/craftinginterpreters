#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/linked_list.h"

extern linked_list_status stat;

void test_linked_list_init() {
  linked_list_t *t = linked_list_init();

  assert(t != NULL);
  assert(t->data == NULL);
  assert(t->next == NULL);
  linked_list_free(t);
}

void test_linked_list_insert() {
  linked_list_t *t = linked_list_init();
  if (stat != linked_list_success) {
    fprintf(stderr, "test_linked_list_insert could not init list: %s\n",
            linked_list_strerror());
    exit(1);
  }

  /* Test Single insert */
  linked_list_insert(t, "hello", 6);
  if (stat != linked_list_success) {
    fprintf(stderr, "test_linked_list_insert could not insert: %s\n",
            linked_list_strerror());
    exit(1);
  }

  assert(linked_list_length(t) == 1);
  assert(strncmp(t->data, "hello", 6) == 0);

  /* Test Second insert */
  linked_list_insert(t, "world", 6);
  if (stat != linked_list_success) {
    fprintf(stderr, "test_linked_list_insert could not insert: %s\n",
            linked_list_strerror());
  }

  assert(linked_list_length(t) == 2);
  assert(strncmp(t->data, "hello", 6) == 0);
  linked_list_t *temp = t->next;
  assert(temp != NULL);
  assert(strncmp(temp->data, "world", 6) == 0);

  linked_list_free(t);
}

void test_linked_list_find() {
  linked_list_t *t = linked_list_init();
  if (stat != linked_list_success) {
    fprintf(stderr, "test_linked_list_find could not init list: %s\n",
            linked_list_strerror());
    exit(1);
  }

  linked_list_insert(t, "hello", 6);
  linked_list_insert(t, "world", 6);

  assert(linked_list_find(t, "hello", 6) == 1);
  assert(linked_list_find(t, "world", 6) == 2);

  linked_list_free(t);
}

void test_linked_list_delete() {
  linked_list_t *t = linked_list_init();
  if (stat != linked_list_success) {
    fprintf(stderr, "test_linked_list_delete could not init list: %s\n",
            linked_list_strerror());
    exit(1);
  }

  linked_list_insert(t, "hello", 6);
  linked_list_insert(t, "world", 6);
  linked_list_insert(t, "!", 1);

  linked_list_delete(t, 1);
  if (stat != linked_list_success) {
    fprintf(stderr, "test_linked_delete could not delete: %s\n", linked_list_strerror());
    exit(1);
  }

  assert(linked_list_length(t) == 2);
  assert(strncmp(t->data, "hello", 6) == 0);
  assert(strncmp(t->next->data, "!", 1) == 0);

  linked_list_free(t);
}

void test_linked_list_delete_last() {
  linked_list_t *t = linked_list_init();
  if (stat != linked_list_success) {
    fprintf(stderr, "test_linked_list_delete could not init list: %s\n",
            linked_list_strerror());
    exit(1);
  }

  linked_list_insert(t, "hello", 6);
  linked_list_insert(t, "world", 6);

  linked_list_delete(t, 1);
  if (stat != linked_list_success) {
    fprintf(stderr, "test_linked_delete could not delete: %s\n", linked_list_strerror());
    exit(1);
  }

  assert(linked_list_length(t) == 1);
  assert(strncmp(t->data, "hello", 6) == 0);
  assert(t->next == NULL);

  linked_list_free(t);
}

void test_linked_list_length() {
  linked_list_t *t = linked_list_init();
  if (stat != linked_list_success) {
    fprintf(stderr, "test_linked_list_length could not init list: %s\n",
            linked_list_strerror());
    exit(1);
  }

  assert(linked_list_length(t) == 0);

  linked_list_free(t);
}

int main(void) {
  test_linked_list_init();
  test_linked_list_insert();
  test_linked_list_find();
  test_linked_list_delete();
  test_linked_list_delete_last();
  test_linked_list_length();
  return 0;
}
