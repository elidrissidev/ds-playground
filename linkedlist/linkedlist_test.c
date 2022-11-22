#include <assert.h>
#include <stdio.h>
#include "linkedlist.h"

int main()
{
    linkedlist_t *list = linkedlist_init();

    assert(linkedlist_size(list) == 0);
    assert(linkedlist_is_empty(list) == 1);

    linkedlist_push_front(list, 2);
    linkedlist_push_front(list, 1);
    linkedlist_push_back(list, 3);

    assert(linkedlist_size(list) == 3);
    assert(linkedlist_is_empty(list) == 0);

    linkedlist_free(list);
    return 0;
}
