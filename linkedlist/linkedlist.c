#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

static void linkedlist_validate_index(linkedlist_t *list, int index)
{
    if (index < 0 || index >= list->size) {
        printf("error: index %d out of boundary.\n", index);
        exit(EXIT_FAILURE);
    }
}

linkedlist_t *linkedlist_init()
{
    linkedlist_t *list = malloc(sizeof(linkedlist_t));

    if (list == NULL) {
        printf("error: could not allocate the resources needed for the list.\n");
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->size = 0;

    return list;
}

int linkedlist_size(linkedlist_t *list)
{
    return list->size;
}

int linkedlist_is_empty(linkedlist_t *list)
{
    return list->size == 0;
}

int linkedlist_value_at(linkedlist_t *list, int index)
{
    linkedlist_validate_index(list, index);

    int i = 0;
    node_t *next_node = list->head;

    while (next_node != NULL) {
        if (i == index) {
            break;
        }

        i++;
        next_node = next_node->next;
    }

    return next_node->value;
}

void linkedlist_push_front(linkedlist_t *list, int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->next = NULL;
    node->value = value;

    if (list->head != NULL) {
        node->next = list->head;
    }

    list->head = node;
    list->size++;
}

int linkedlist_pop_front(linkedlist_t *list)
{
    if (list->size == 0) {
        printf("error: cannot pop an element from an empty list.\n");
        exit(EXIT_FAILURE);
    }

    node_t *node = list->head;
    int value = node->value;

    list->head = node->next;
    list->size--;

    free(node);

    return value;
}

void linkedlist_free(linkedlist_t *list)
{
    node_t *current_node = list->head;

    while (current_node != NULL) {
        node_t *next_node = current_node->next;

        free(current_node);

        current_node = next_node;
    }

    free(list);
}
