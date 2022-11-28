#include <assert.h>
#include <stdio.h>
#include "queue_list.h"

int main()
{
	queue_t *queue = queue_init();

	assert(queue_size(queue) == 0);
	assert(queue_is_empty(queue) == 1);

	queue_enqueue(queue, 10);
	queue_enqueue(queue, 50);

	assert(queue_size(queue) == 2);
	assert(queue_is_empty(queue) == 0);

	queue_free(queue);
	return 0;
}
