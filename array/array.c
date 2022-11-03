#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

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
        printf("error: array index %d out of bounds.", index);
        exit(EXIT_FAILURE);
    }

    return *(array->items + index);
}

void array_free(array_t *array)
{
    free(array->items);
    free(array);
}

int main()
{
    return 0;
}
