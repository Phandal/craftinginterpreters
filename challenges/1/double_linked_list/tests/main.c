#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../src/linked_list.h"

void test_linked_list_init() {
  linked_list_t t;

  linked_list_init(&t);

  assert(t.data == NULL);
  assert(t.next == NULL);
  linked_list_free(&t);
}

void test_linked_list_insert_at_end() {
  linked_list_t t;
  if (linked_list_init(&t) != linked_list_success) {
    fprintf(stderr, "test_linked_list_insert_at_end could not init list\n");
    exit(1);
  }

  if (linked_list_insert(&t, "hello", 6, 0) != linked_list_success) {
    fprintf(stderr, "test_linked_list_insert_at_end could not insert\n");
    exit(1);
  }

  assert(linked_list_length(&t) == 1);
  assert(strncmp(t.data, "hello", 6) == 0);

  linked_list_free(&t);
}

void test_linked_list_length() {
  linked_list_t t;
  if (linked_list_init(&t) != linked_list_success) {
    fprintf(stderr, "test_linked_list_length could not init list\n");
    exit(1);
  }

  assert(linked_list_length(&t) == 0);

  linked_list_free(&t);
}

int main(void) {
  test_linked_list_init();
  test_linked_list_insert_at_end();
  test_linked_list_length();
  return 0;
}
