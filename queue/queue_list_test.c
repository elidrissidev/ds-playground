#include <assert.h>
#include <stdio.h>
#include "queue_list.h"

int main()
{
	queue_t *queue = queue_init();

	assert(queue_size(queue) == 0);
	assert(queue_is_empty(queue) == 1);

	queue_enqueue(queue, 10);
	queue_enqueue(queue, 40);
	queue_enqueue(queue, 70);

	assert(queue_size(queue) == 3);
	assert(queue_is_empty(queue) == 0);

    assert(queue_dequeue(queue) == 10);
    assert(queue_dequeue(queue) == 40);
    assert(queue_dequeue(queue) == 70);

    assert(queue_size(queue) == 0);

	queue_free(queue);
	return 0;
}
