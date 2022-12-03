#include <stdio.h>
#include <stdlib.h>
#include "queue_array.h"

queue_t *queue_init(int capacity)
{
    queue_t *queue = malloc(sizeof(queue_t));
    // we need an additional slot to separate the read and write indexes.
    int *items = malloc((capacity + 1) * sizeof(int));

    if (queue == NULL || items == NULL) {
        printf("error: could not allocate the resources needed for the queue.\n");
        exit(EXIT_FAILURE);
    }

    queue->size = 0;
    queue->capacity = capacity;
    queue->items = items;
    queue->read = queue->write = 0;

    return queue;
}

void queue_enqueue(queue_t *queue, int value)
{
    if (queue_is_full(queue)) {
        printf("error: queue is full.\n");
        exit(EXIT_FAILURE);
    }

    *(queue->items + queue->write) = value;

    if (queue->write == queue->capacity) {
        queue->write = 0;
    } else {
        queue->write++;
    }

    queue->size++;
}

int queue_dequeue(queue_t *queue)
{
    int value = *(queue->items + queue->read);

    if (queue->read == queue->capacity) {
        queue->read = 0;
    } else {
        queue->read++;
    }

    queue->size--;

    return value;
}

int queue_size(queue_t *queue)
{
    return queue->size;
}

int queue_capacity(queue_t *queue)
{
    return queue->capacity;
}

int queue_is_empty(queue_t *queue)
{
    return queue->size == 0;
}

int queue_is_full(queue_t *queue)
{
    return queue->size == queue->capacity;
}

void queue_free(queue_t *queue)
{
    free(queue->items);
    free(queue);
}
