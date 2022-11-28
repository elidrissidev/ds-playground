#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

int main()
{
	int initial_capacity = 4;
	ds_stack_t *stack = stack_init(initial_capacity);

	assert(stack_capacity(stack) == initial_capacity);
	assert(stack_size(stack) == 0);
	assert(stack_is_empty(stack) == 1);

	// this string contains one opening curly brace at index 8 with no matching closing pair.
	char *str = "{}{{{}}}{{{}}{{{}}}";
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		if (str[i] == '{') {
			stack_push(stack, i);
		} else if (! stack_is_empty(stack)) {
			stack_pop(stack);
		}
	}

	assert(stack_size(stack) == 1);
	assert(stack_capacity(stack) == 2);
	assert(stack_peek(stack) == 8);
	assert(stack_pop(stack) == 8);

	stack_free(stack);
	return 0;
}
