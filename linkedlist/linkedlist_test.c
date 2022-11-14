#include <assert.h>
#include <stdio.h>
#include "linkedlist.h"

int main()
{
    linkedlist_t *list = linkedlist_init();

    linkedlist_push_front(list, 3);
    linkedlist_push_front(list, 2);
    linkedlist_push_front(list, 1);

    linkedlist_erase(list, 1);

    assert(linkedlist_size(list) == 2);
    assert(linkedlist_value_at(list, 0) == 1);
    assert(linkedlist_value_at(list, 1) == 3);

    linkedlist_free(list);
    return 0;
}
