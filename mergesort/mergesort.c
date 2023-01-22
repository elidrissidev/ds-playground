#include <assert.h>
#include <stdio.h>
#include "../array/array.h"

#define SORT_ASC 1
#define SORT_DESC -1

static void merge(array_t *arr, array_t *copy_arr, int dir, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;

    for (int k = start; k <= end; k++) {
        array_set(copy_arr, k, array_at(arr, k));
    }

    for (int k = start; k <= end; k++) {
        if (i > mid) {
            array_set(arr, k, array_at(copy_arr, j++));
        } else if (j > end) {
            array_set(arr, k, array_at(copy_arr, i++));
        } else {
            int left_value = array_at(copy_arr, i);
            int right_value = array_at(copy_arr, j);

            if ((left_value > right_value && dir == SORT_ASC) ||
                (left_value < right_value && dir == SORT_DESC)) {
                array_set(arr, k, right_value);
                j++;
            } else {
                array_set(arr, k, left_value);
                i++;
            }
        }
    }
}

static void recursive_merge_sort(array_t *arr, array_t *copy_arr, int dir, int start, int end)
{
    if (start == end) {
        return;
    }

    // In C, math operations on integers always result in an integer
    int mid = (end - start) / 2 + start;
    recursive_merge_sort(arr, copy_arr, dir, start, mid);
    recursive_merge_sort(arr, copy_arr, dir, mid + 1, end);
    merge(arr, copy_arr, dir, start, mid, end);
}

void merge_sort(array_t *arr, int dir)
{
    array_t *copy_arr = array_clone(arr);
    recursive_merge_sort(arr, copy_arr, dir, 0, array_size(arr) - 1);
    array_free(copy_arr);
}

int main()
{
    array_t *arr = array_init(8);
    array_push(arr, 1);
    array_push(arr, 4);
    array_push(arr, 2);
    array_push(arr, 8);
    array_push(arr, 43);
    array_push(arr, 11);
    array_push(arr, 2);

    array_t *asc_arr = array_clone(arr);
    merge_sort(asc_arr, SORT_ASC);

    assert(array_at(asc_arr, 0) == 1);
    assert(array_at(asc_arr, 1) == 2);
    assert(array_at(asc_arr, 2) == 2);
    assert(array_at(asc_arr, 3) == 4);
    assert(array_at(asc_arr, 4) == 8);
    assert(array_at(asc_arr, 5) == 11);
    assert(array_at(asc_arr, 6) == 43);

    array_t *desc_arr = array_clone(arr);
    merge_sort(desc_arr, SORT_DESC);

    assert(array_at(desc_arr, 0) == 43);
    assert(array_at(desc_arr, 1) == 11);
    assert(array_at(desc_arr, 2) == 8);
    assert(array_at(desc_arr, 3) == 4);
    assert(array_at(desc_arr, 4) == 2);
    assert(array_at(desc_arr, 5) == 2);
    assert(array_at(desc_arr, 6) == 1);

    array_free(arr);
    array_free(asc_arr);
    array_free(desc_arr);
    return 0;
}
