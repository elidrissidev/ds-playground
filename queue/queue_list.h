#ifndef _QUEUE_LIST_H
#define _QUEUE_LIST_H

typedef struct node {
	int value;
	struct node *next;
} node_t;

typedef struct queue {
	int size;
	node_t *head;
	node_t *tail;
} queue_t;

// Returns a new queue struct.
queue_t *queue_init();

// Adds a new value to the queue.
void queue_enqueue(queue_t *queue, int value);

// Removes and returns the least-recently added element from the queue.
int queue_dequeue(queue_t *queue);

// Returns the number of elements in the queue.
int queue_size(queue_t *queue);

// Returns whether the queue is empty.
int queue_is_empty(queue_t *queue);

// Frees all the resources held by the queue. Once this function is called, the queue is no longer usable.
void queue_free(queue_t *queue);

#endif
