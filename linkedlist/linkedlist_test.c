#include <assert.h>
#include <stdio.h>
#include "linkedlist.h"

int main()
{
    linkedlist_t *list = linkedlist_init();

    assert(list->head == NULL);
    assert(list->size == 0);

    linkedlist_push_front(list, 1);
    linkedlist_push_front(list, 1);

    assert(linkedlist_size(list) == 2);
    assert(linkedlist_is_empty(list) == 0);

    assert(linkedlist_value_at(list, 1) == 1);
    assert(linkedlist_pop_front(list) == 1);
    assert(linkedlist_size(list) == 1);

    linkedlist_free(list);
    return 0;
}
