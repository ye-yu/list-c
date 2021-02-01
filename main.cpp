#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "longlist.h"

void *printchar(void *c) {
  char chr = *(char *)c;
  putchar(chr);
  return NULL;
}

int main() {
  list_container *c = (list_container *) malloc(sizeof(list_container));
  list_new(1, LONG_LIST_TYPE_STACK, c);
  const char *str = "hello\n";

  list_push_item_tail(c, (void *)str);
  list_push_item_tail(c, (void *)(str + 1));
  list_push_item_tail(c, (void *)(str + 2));
  list_push_item_tail(c, (void *)(str + 3));
  list_push_item_tail(c, (void *)(str + 4));
  list_push_item_tail(c, (void *)(str + 5));
  list_for_each(*c, *printchar);
  list_destroy(c);
  free(c);
}