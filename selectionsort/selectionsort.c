#include <assert.h>
#include <stdio.h>
#include "../array/array.h"

#define SORT_ASC 1
#define SORT_DESC -1

array_t *selection_sort(array_t *arr, int dir)
{
    array_t *unsorted_arr = array_clone(arr);
    array_t *sorted_arr = array_init(array_capacity(unsorted_arr));

    while (array_size(unsorted_arr) > 0) {
        int index = 0;
        int value = array_at(unsorted_arr, 0);
        int size = array_size(unsorted_arr);

        for (int i = 1; i < size; i++) {
            int previous = array_at(unsorted_arr, i - 1);
            int current = array_at(unsorted_arr, i);
            printf("unsorted_arr[%d]; previous: %d; current: %d\n", i, previous, current);

            if (previous - current > 0) {
                index = dir == SORT_ASC ? i : i - 1;
                value = dir == SORT_ASC ? current : previous;
            } else if (previous - current < 0) {
                index = dir == SORT_ASC ? i - 1 : i;
                value = dir == SORT_ASC ? previous : current;
            }
        }

        array_delete(unsorted_arr, index);
        array_push(sorted_arr, value);
    }
    array_free(unsorted_arr);
    return sorted_arr;
}

int main()
{
    // {64, 12, 22, 31, 15}
    array_t *arr = array_init(8);
    array_push(arr, 64);
    array_push(arr, 12);
    array_push(arr, 22);
    array_push(arr, 31);
    array_push(arr, 15);

    array_t *asc_arr = selection_sort(arr, SORT_ASC);

    for (int i = 0; i < array_size(asc_arr); i++) {
        printf("asc_arr[%d] = %d\n", i, array_at(asc_arr, i));
    }

    assert(array_at(asc_arr, 0) == 12);
    assert(array_at(asc_arr, 1) == 15);
    assert(array_at(asc_arr, 2) == 22);
    assert(array_at(asc_arr, 3) == 31);
    assert(array_at(asc_arr, 4) == 64);

    array_t *desc_arr = selection_sort(arr, SORT_DESC);
    assert(array_at(asc_arr, 0) == 64);
    assert(array_at(asc_arr, 1) == 31);
    assert(array_at(asc_arr, 2) == 22);
    assert(array_at(asc_arr, 3) == 15);
    assert(array_at(asc_arr, 4) == 12);

    array_free(arr);
    array_free(asc_arr);
    array_free(desc_arr);
    return 0;
}
