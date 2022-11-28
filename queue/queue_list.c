#include <stdio.h>
#include <stdlib.h>
#include "queue_list.h"

queue_t *queue_init()
{
	queue_t *queue = malloc(sizeof(queue_t));

	if (queue == NULL) {
		printf("error: could not allocate the resources needed for the queue list.\n");
		exit(EXIT_FAILURE);
	}

	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;

	return queue;
}

void queue_enqueue(queue_t *queue, int value)
{
	node_t *node = malloc(sizeof(node_t));

	if (node == NULL) {
		printf("error: could not allocate the resources needed for a new node.\n");
		exit(EXIT_FAILURE);
	}

	node->next = NULL;
	node->value = value;

	if (queue->size == 0) {
		queue->head = queue->tail = node;
	} else {
		queue->tail = queue->tail->next = node;
	}

	queue->size++;
}

int queue_size(queue_t *queue)
{
	return queue->size;
}

int queue_is_empty(queue_t *queue)
{
	return queue->size == 0;
}

void queue_free(queue_t *queue)
{
	node_t *current = queue->head;

	while (current != NULL) {
		node_t *next = current->next;

		free(current);

		current = next;
	}

	free(queue);
}
