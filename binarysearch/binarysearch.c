#include <assert.h>
#include <stdio.h>
#include "../array/array.h"

int binary_search(array_t *arr, int search)
{
	int left = 0;
	int right = array_size(arr) - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		int mid_value = array_at(arr, mid);

		if (mid_value > search) {
			right = mid - 1;
		} else if (mid_value < search) {
			left = mid + 1;
		} else {
			return mid;
		}
	}

	return -1;
}

int main()
{
	// Build an array with numbers from 1 to 100
	array_t *arr = array_init(100);

	for (int i = 1; i <= 100; i++) {
		array_push(arr, i);
	}

	assert(binary_search(arr, 50) == 49);
	assert(binary_search(arr, 14) == 13);
	assert(binary_search(arr, 100) == 99);
	assert(binary_search(arr, 88) == 87);
	assert(binary_search(arr, 12) == 11);
	assert(binary_search(arr, 35) == 34);
	assert(binary_search(arr, 119) == -1);
	assert(binary_search(arr, 0) == -1);

	array_free(arr);
	return 0;
}
