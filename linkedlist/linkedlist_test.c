#include <assert.h>
#include <stdio.h>
#include "linkedlist.h"

int main()
{
    linkedlist_t *list = linkedlist_init();

    assert(linkedlist_pop_back(list) == 10);
    assert(linkedlist_size(list) == 1);

    assert(list->head == NULL);
    assert(list->size == 0);

    linkedlist_push_front(list, 1);
    linkedlist_push_front(list, 1);

    assert(linkedlist_size(list) == 2);
    assert(linkedlist_is_empty(list) == 0);

    assert(linkedlist_value_at(list, 1) == 1);
    assert(linkedlist_pop_front(list) == 1);
    assert(linkedlist_size(list) == 1);

    linkedlist_push_back(list, 1);
    linkedlist_push_back(list, 2);
    linkedlist_push_back(list, 5);

    assert(linkedlist_value_at(list, 2) == 2);
    assert(linkedlist_pop_back(list) == 5);
    assert(linkedlist_size(list) == 3);

    linkedlist_free(list);
    return 0;
}
