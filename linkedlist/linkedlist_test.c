#include <assert.h>
#include <stdio.h>
#include "linkedlist.h"

int main()
{
    linkedlist_t *list = linkedlist_init();

    assert(linkedlist_size(list) == 0);
    assert(linkedlist_is_empty(list) == 1);

    linkedlist_push_back(list, 1);
    linkedlist_push_back(list, 2);
    linkedlist_push_back(list, 3);

    assert(linkedlist_size(list) == 3);
    assert(linkedlist_is_empty(list) == 0);

    linkedlist_push_front(list, 1);
    linkedlist_push_front(list, 1);

    assert(linkedlist_value_at(list, 2) == 1);
    assert(linkedlist_value_at(list, 3) == 2);
    assert(linkedlist_value_at(list, 4) == 3);

    linkedlist_insert(list, 2, 99);

    linkedlist_erase(list, 1);
    linkedlist_remove_value(list, 99);

    assert(linkedlist_value_at(list, 2) == 2);
    assert(linkedlist_size(list) == 4);
    assert(linkedlist_front(list) == 1);
    assert(linkedlist_back(list) == 3);

    linkedlist_reverse(list);

    // If everything goes well, we should have the first 5 digits of
    // fib sequence in reverse order!
    assert(linkedlist_value_at(list, 0) == 3);
    assert(linkedlist_value_at(list, 1) == 2);
    assert(linkedlist_value_at(list, 2) == 1);
    assert(linkedlist_value_at(list, 3) == 1);

    linkedlist_free(list);
    return 0;
}
