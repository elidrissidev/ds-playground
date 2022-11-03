#ifndef _ARRAY_H
#define _ARRAY_H

typedef struct array {
    int size;
    int capacity;
    int *items;
} array_t;

// Initializes a new array struct with the given initial capacity.
array_t *array_init(int capacity);

// Returns the number of items contained in the array.
int array_size(array_t *array);

// Returns the total capacity of the array.
int array_capacity(array_t *array);

// Returns whether the array contains any items or not.
int array_is_empty(array_t *array);

// Returns the item at the given index.
int array_at(array_t *array, int index);

// Inserts an item at the end of the array.
void array_push(array_t *array, int item);

// Inserts an item at the given index, shifting the following items forward, if any.
void array_insert(array_t *array, int item);

// Inserts an item at the start of the array, shifting the following items forward, if any.
void array_prepend(array_t *array, int item);

// Removes and returns an item from the end of the array.
int array_pop(array_t *array);

// Removes an item at the given index, shifting the following items backwards, if any.
void array_delete(array_t *array, int index);

// Removes all occurrences of the given item from the array.
void array_remove(array_t *array, int item);

// Returns the index of the first occurrence of the given item, or -1 if it was not found.
int array_find(array_t *array, int item);

void array_free(array_t *array);

#endif
