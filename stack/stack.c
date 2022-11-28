#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static void stack_resize(ds_stack_t *stack, int new_capacity)
{
	int *new_items = realloc(stack->items, new_capacity * sizeof(int));

	if (new_items == NULL) {
		printf("error: failed to resize stack from capacity %d to %d.\n", stack->capacity, new_capacity);
		exit(EXIT_FAILURE);
	}

	stack->items = new_items;
	stack->capacity = new_capacity;
}

ds_stack_t *stack_init(int capacity)
{
	ds_stack_t *stack = malloc(sizeof(ds_stack_t));
	int *items = malloc(capacity * sizeof(int));

	if (stack == NULL || items == NULL) {
		printf("error: could not allocate the resources needed for the stack.\n");
		exit(EXIT_FAILURE);
	}

	stack->size = 0;
	stack->capacity = capacity;
	stack->items = items;

	return stack;
}

int stack_size(ds_stack_t *stack)
{
	return stack->size;
}

int stack_capacity(ds_stack_t *stack)
{
	return stack->capacity;
}

int stack_is_empty(ds_stack_t *stack)
{
	return stack->size == 0;
}

void stack_push(ds_stack_t *stack, int item)
{
	if (stack->size == stack->capacity) {
		stack_resize(stack, stack->capacity * 2);
	}

	*(stack->items + stack->size) = item;
	stack->size++;
}

int stack_pop(ds_stack_t *stack)
{
	if (stack->size == 0) {
		printf("error: could not pop from an empty stack.\n");
		exit(EXIT_FAILURE);
	}

	int item = *(stack->items + stack->size - 1);
	stack->size--;

	if (((float) stack->size / (float) stack->capacity) <= 0.25) {
		stack_resize(stack, stack->capacity / 2);
	}

	return item;
}

int stack_peek(ds_stack_t *stack)
{
	if (stack->size == 0) {
		printf("error: could not peek at an empty stack.\n");
		exit(EXIT_FAILURE);
	}

	return *(stack->items + stack->size - 1);
}

void stack_free(ds_stack_t *stack)
{
	free(stack->items);
	free(stack);
}
