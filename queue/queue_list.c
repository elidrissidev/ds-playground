#include <stdio.h>
#include <stdlib.h>
#include "queue_list.h"

// We could technically use the linkedlist implementation for the queue but I'm choosing not to,
// to keep it simple, and because the extra functionality of linkedlist (push, pop, remove at index...)
// doesn't make much sense in a queue anyways.

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

int queue_dequeue(queue_t *queue)
{
    if (queue->size == 0) {
        printf("error: could not dequeue from an empty queue.\n");
        exit(EXIT_FAILURE);
    }

    node_t *head = queue->head;
    int value = head->value;

    if (queue->size == 1) {
        // the element we're dequeuing is the last one,
        // so we need to clear the tail pointer.
        queue->head = queue->tail = NULL;
    } else {
        queue->head = head->next;
    }

    free(head);

    queue->size--;

    return value;
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
