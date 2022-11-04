#include <assert.h>
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

    array_free(arr);
    return 0;
}
