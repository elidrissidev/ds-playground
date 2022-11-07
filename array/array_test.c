#include <assert.h>
#include <stdio.h>
#include "array.h"

int main()
{
    int initial_capacity = 2;
    array_t *arr = array_init(initial_capacity);

    array_push(arr, 1);
    array_push(arr, 2);
    array_push(arr, 3);
    array_push(arr, 2);
    array_push(arr, 2);

    printf("Before:\n");
    for (int i = 0; i < arr->size; i++) {
        printf("arr[%d] = %d\n", i, *(arr->items + i));
    }

    array_remove(arr, 2);

    printf("After:\n");
    for (int i = 0; i < arr->size; i++) {
        printf("arr[%d] = %d\n", i, *(arr->items + i));
    }

    array_free(arr);
    return 0;
}
