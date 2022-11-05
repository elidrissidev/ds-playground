#include <assert.h>
#include <stdio.h>
#include "array.h"

int main()
{
    int initial_capacity = 2;
    array_t *arr = array_init(initial_capacity);

    // Ensure the array was initialized properly
    assert(array_capacity(arr) == initial_capacity);
    assert(array_size(arr) == 0);
    assert(array_is_empty(arr) == 1);

    // Push some items to the array such that it gets resized
    array_push(arr, 1);
    array_push(arr, 2);
    array_push(arr, 3);

    // Ensure the array was resized successfully
    assert(array_capacity(arr) == (initial_capacity * 2));
    assert(array_size(arr) == 3);
    assert(array_is_empty(arr) == 0);

    printf("Before:\n");
    for (int i = 0; i < arr->size; i++) {
        printf("arr[%d] = %d\n", i, *(arr->items + i));
    }

    array_insert(arr, 3, 4);
    array_prepend(arr, 5);

    printf("After:\n");
    for (int i = 0; i < arr->size; i++) {
        printf("arr[%d] = %d\n", i, *(arr->items + i));
    }

    assert(array_pop(arr) == 4);
    assert(array_pop(arr) == 3);

    array_free(arr);
    return 0;
}
