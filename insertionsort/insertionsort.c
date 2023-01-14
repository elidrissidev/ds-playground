#include <assert.h>
#include <stdio.h>
#include "../array/array.h"

#define SORT_ASC 1
#define SORT_DESC -1

array_t *insertion_sort(array_t *arr, int dir)
{
    array_t *sorted_arr = array_clone(arr);

    if (array_size(sorted_arr) <= 1) {
        return sorted_arr;
    }

    for (int i = 1; i < array_size(sorted_arr); i++) {
        int previous = array_at(sorted_arr, i - 1);
        int current = array_at(sorted_arr, i);

        if ((previous - current > 0 && dir == SORT_ASC) ||
            (previous - current < 0 && dir == SORT_DESC)
        ) {
            array_set(sorted_arr, i - 1, current);
            array_set(sorted_arr, i, previous);
        }

        for (int j = i; j > 0; j--) {
            previous = array_at(sorted_arr, j - 1);
            current = array_at(sorted_arr, j);

            if ((previous - current > 0 && dir == SORT_ASC) ||
                (previous - current < 0 && dir == SORT_DESC)
            ) {
                array_set(sorted_arr, j - 1, current);
                array_set(sorted_arr, j, previous);
            }
        }
    }
    return sorted_arr;
}

int main()
{
    array_t *arr = array_init(8);
    array_push(arr, 12);
    array_push(arr, 11);
    array_push(arr, 13);
    array_push(arr, 5);
    array_push(arr, 6);

    array_t *asc_arr = insertion_sort(arr, SORT_ASC);
    assert(array_at(asc_arr, 0) == 5);
    assert(array_at(asc_arr, 1) == 6);
    assert(array_at(asc_arr, 2) == 11);
    assert(array_at(asc_arr, 3) == 12);
    assert(array_at(asc_arr, 4) == 13);

    array_t *desc_arr = insertion_sort(arr, SORT_DESC);
    assert(array_at(desc_arr, 0) == 13);
    assert(array_at(desc_arr, 1) == 12);
    assert(array_at(desc_arr, 2) == 11);
    assert(array_at(desc_arr, 3) == 6);
    assert(array_at(desc_arr, 4) == 5);

    array_free(arr);
    array_free(asc_arr);
    array_free(desc_arr);
    return 0;
}
