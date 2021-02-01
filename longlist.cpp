#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "longlist.h"

const double LIST_GROWTH_FACTOR = 0.75;

const short LIST_GROWTH_MULTIPLIER = 3;

int list_new(const int init_size, const list_type type, list_container *obj) {
  obj -> total_length = init_size;
  obj -> length = 0;
  obj -> type = type;
  obj -> items = (void **)malloc(sizeof(void *) * init_size);
  return 0;
}

int expand_on_threshold(list_container *obj) {
  const double threshold = obj -> length / obj -> total_length;
  if (threshold < LIST_GROWTH_FACTOR) return 0;

  obj -> total_length *= 2;
  void **tmp_items = (void **)malloc(sizeof(void *) * obj -> total_length);
  for (size_t i = 0; i < obj -> length; i++)
  {
    tmp_items[i] = obj -> items[i];
  }
  free(obj -> items);
  obj -> items = tmp_items;
  printf("Expanding memory allocation: was %d, now %d\n", obj -> total_length / 2, obj -> total_length);
  return 0;
}

int list_push_item_head(list_container *obj, void *item) {
  const int on_expand = expand_on_threshold(obj);
  if (on_expand != 0) return LIST_ERROR_FAULT_IN_ALLOCATION;

  for (size_t i = obj -> length; i >= 1; i--)
  {
    obj -> items[i] = obj -> items[i - 1];
  }

  obj -> items[0] = item;
  obj -> length++;
  return 0;
}

int list_push_item_tail(list_container *obj, void *item) {
  const int on_expand = expand_on_threshold(obj);
  if (on_expand != 0) return LIST_ERROR_FAULT_IN_ALLOCATION;
  obj -> items[obj -> length] = item;
  obj -> length++;
  return 0;
}

int list_item_at(const int index, list_container *obj, void **return_value) {
  if (index < 0) return LIST_ERROR_OUT_OF_BOUND_LOWER;
  if (index >= obj -> length) return LIST_ERROR_OUT_OF_BOUND_UPPER;
  void *item = &obj -> items[index];
  *return_value = item;
  return 0;
}

int list_for_each(list_container obj, void *(*consumer)(void *)) {
  for (size_t i = 0; i < obj.length; i++)
  {
    consumer(obj.items[i]);
  }
  return 0;
}

int list_split(list_container *source, list_container *destination, const int from, const int to) {
  return 0;
}

int list_destroy(list_container *obj) {
  free(obj -> items);
  return 0;
}
