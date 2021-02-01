#ifndef LONGLIST_H
#define LONGLIST_H 1

typedef enum _list_type {
  LONG_LIST_TYPE_LINKED, 
  LONG_LIST_TYPE_STACK,
  LONG_LIST_TYPE_SET
} list_type;

typedef enum _list_error {
  LIST_ERROR_OUT_OF_BOUND_UPPER,
  LIST_ERROR_OUT_OF_BOUND_LOWER,
  LIST_ERROR_FAULT_IN_ALLOCATION
} list_error;

typedef struct _list_container {
  long length;
  long total_length;
  void** items;
  list_type type;
} list_container;

extern int list_new(const int init_size, const list_type type, list_container *obj);

extern int list_push_item_head(list_container *obj, void *item);

extern int list_push_item_tail(list_container *obj, void *item);

extern int list_item_at(const int index, list_container *obj, void **return_value);

extern int list_for_each(list_container obj, void *(*consumer)(void *));

extern int list_split(list_container *source, list_container *destination, const int from, const int to);

extern int list_destroy(list_container *obj);

#endif
