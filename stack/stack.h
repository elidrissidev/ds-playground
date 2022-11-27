#ifndef _STACK_H
#define _STACK_H

typedef struct stack {
	int size;
	int capacity;
	int *items;
} stack_t;

// Initializes a new stack struct.
stack_t *stack_init(int capacity);

// Returns the number of items contained in the stack.
int stack_size(stack_t *stack);

// Returns the total capacity of the stack.
int stack_capacity(stack_t *stack);

// Returns whether the stack contains no items.
int stack_is_empty(stack_t *stack);

// Adds a new item to the top of the stack.
void stack_push(stack_t *stack, int item);

// Removes and returns the item on top of the stack.
int stack_pop(stack_t *stack);

// Returns the item on top of the stack.
int stack_peek(stack_t *stack);

// Frees all the resources held by the stack. After this function is called, the stack is no longer usable.
void stack_free(stack_t *stack);

#endif
