#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "array.h"

static void array_resize(array_t *array, int new_capacity)
{
    int *new_items = realloc(array->items, new_capacity * sizeof(int));

    if (new_items == NULL) {
        printf("error: failed to resize array from capacity %d to %d.\n", array->capacity, new_capacity);
        exit(EXIT_FAILURE);
    }

    array->capacity = new_capacity;
    array->items = new_items;
}

array_t *array_init(int capacity)
{
    int *items = malloc(capacity * sizeof(int));
    array_t *arr = malloc(sizeof(array_t));

    arr->size = 0;
    arr->capacity = capacity;
    arr->items = items;

    return arr;
}

int array_size(array_t *array)
{
    return array->size;
}

int array_capacity(array_t *array)
{
    return array->capacity;
}

int array_is_empty(array_t *array)
{
    return array->size == 0;
}

int array_at(array_t *array, int index)
{
    if (index < 0 || index >= array->size) {
        printf("error: array index %d out of bounds.\n", index);
        exit(EXIT_FAILURE);
    }

    return *(array->items + index);
}

void array_push(array_t *array, int item)
{
    if (array->size == array->capacity) {
        array_resize(array, array->capacity * 2);
    }

    *(array->items + array->size) = item;
    array->size++;
}

void array_insert(array_t *array, int index, int item)
{
    if (index < 0 || index > array->size) {
        printf("error: array index %d out of bounds.\n", index);
        exit(EXIT_FAILURE);
    }

    if (array->size == array->capacity) {
        array_resize(array, array->capacity * 2);
    }

    if (array->size > 0) {
        // move all the items starting from the given index by 1 block at once so it's O(1),
        // then insert the new item in the freed block.
        memmove(array->items + index + 1, array->items + index, (array->size - index) * sizeof(int));
    }

    *(array->items + index) = item;
    array->size++;
}

void array_prepend(array_t *array, int item)
{
    array_insert(array, 0, item);
}

int array_pop(array_t *array)
{
    if (array->size == 0) {
        printf("error: cannot pop an item from an empty array.");
        exit(EXIT_FAILURE);
    }

    if ((array->size / array->capacity) <= 0.25) {
        // resize to half capacity if only 25% of the array's capacity is used
        array_resize(array, array->capacity / 2);
    }

    int item = *(array->items + array->size - 1);
    *(array->items + array->size - 1) = 0;
    array->size--;

    return item;
}

void array_delete(array_t *array, int index)
{
    if (index < 0 || index >= array->size) {
        printf("error: array index %d out of bounds.\n", index);
        exit(EXIT_FAILURE);
    }

    memmove(array->items + index, array->items + index + 1, (array->size - index - 1) * sizeof(int));

    array->size--;

    if ((array->size / array->capacity) <= 0.25) {
        // resize to half capacity if only 25% of the array's capacity is used
        array_resize(array, array->capacity / 2);
    }
}

int array_find(array_t *array, int item)
{
    for (int i = 0; i < array->size; i++) {
        if (*(array->items + i) == item) {
            return i;
        }
    }
    return -1;
}

void array_free(array_t *array)
{
    free(array->items);
    free(array);
}
