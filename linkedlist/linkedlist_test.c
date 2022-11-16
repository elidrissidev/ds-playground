#include <assert.h>
#include <stdio.h>
#include "linkedlist.h"

int main()
{
    linkedlist_t *list = linkedlist_init();

    linkedlist_push_front(list, 3);
    linkedlist_push_front(list, 2);
    linkedlist_push_front(list, 1);

    assert(linkedlist_value_n_from_end(list, 1) == 3);
    assert(linkedlist_value_n_from_end(list, 2) == 2);
    assert(linkedlist_value_n_from_end(list, 3) == 1);

    linkedlist_free(list);
    return 0;
}
