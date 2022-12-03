#include <assert.h>
#include "queue_array.h"

int main()
{
    int capacity = 2;
    queue_t *queue = queue_init(capacity);

    assert(queue_size(queue) == 0);
    assert(queue_capacity(queue) == capacity);
    assert(queue_is_empty(queue) == 1);
    assert(queue_is_full(queue) == 0);

    queue_enqueue(queue, 3);
    queue_enqueue(queue, 7);

    assert(queue_size(queue) == 2);
    assert(queue_is_empty(queue) == 0);
    assert(queue_is_full(queue) == 1);

    assert(queue_dequeue(queue) == 3);

    queue_enqueue(queue, 8);

    assert(queue_dequeue(queue) == 7);

    queue_enqueue(queue, 11);

    assert(queue_is_full(queue) == 1);

    assert(queue_dequeue(queue) == 8);
    assert(queue_size(queue) == 1);
    assert(queue_is_full(queue) == 0);

    queue_free(queue);
    return 0;
}
