#include <assert.h>
#include <stdio.h>
#include "../array/array.h"

#define SORT_ASC 1
#define SORT_DESC -1

array_t *bubble_sort(array_t *arr, int dir)
{
    array_t *sorted_arr = array_clone(arr);
    int size = array_size(sorted_arr);

    if (size <= 1) {
        return sorted_arr;
    }

    int swaps;

    do {
        swaps = 0;

        for (int i = 1; i < size; i++) {
            int previous = array_at(sorted_arr, i - 1);
            int current = array_at(sorted_arr, i);

            if ((previous > current && dir == SORT_ASC) ||
                (previous < current && dir == SORT_DESC)
            ) {
                array_set(sorted_arr, i - 1, current);
                array_set(sorted_arr, i, previous);
                swaps++;
            }
        }
    } while (swaps > 0);

    return sorted_arr;
}

int main()
{
    array_t *arr = array_init(8);
    array_push(arr, 5);
    array_push(arr, 1);
    array_push(arr, 4);
    array_push(arr, 2);
    array_push(arr, 8);

    array_t *asc_arr = bubble_sort(arr, SORT_ASC);
    assert(array_at(asc_arr, 0) == 1);
    assert(array_at(asc_arr, 1) == 2);
    assert(array_at(asc_arr, 2) == 4);
    assert(array_at(asc_arr, 3) == 5);
    assert(array_at(asc_arr, 4) == 8);

    array_t *desc_arr = bubble_sort(arr, SORT_DESC);
    assert(array_at(desc_arr, 0) == 8);
    assert(array_at(desc_arr, 1) == 5);
    assert(array_at(desc_arr, 2) == 4);
    assert(array_at(desc_arr, 3) == 2);
    assert(array_at(desc_arr, 4) == 1);

    array_free(arr);
    array_free(asc_arr);
    array_free(desc_arr);
    return 0;
}
