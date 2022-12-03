#ifndef _QUEUE_ARRAY_H
#define _QUEUE_ARRAY_H

typedef struct queue {
	int size;
    int capacity;
    int *items;
    int read;
    int write;
} queue_t;

// Returns a new queue struct.
queue_t *queue_init(int capacity);

// Adds a new value to the queue.
void queue_enqueue(queue_t *queue, int value);

// Removes and returns the least-recently added value from the queue.
int queue_dequeue(queue_t *queue);

// Returns the number of values in the queue.
int queue_size(queue_t *queue);

// Returns the capacity of the queue.
int queue_capacity(queue_t *queue);

// Returns whether the queue is empty.
int queue_is_empty(queue_t *queue);

// Returns whether the queue is at its capacity.
int queue_is_full(queue_t *queue);

// Frees all the resources held by the queue. Once this function is called, the queue is no longer usable.
void queue_free(queue_t *queue);

#endif
