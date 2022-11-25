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

    // we're going to use a dummy/sentinel node for the head element
    // for a simpler implementation of certain functionalities of the list.
    node_t *dummy_head = malloc(sizeof(node_t));
    dummy_head->next = NULL;
    dummy_head->value = 0;

    list->head = dummy_head;
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
    node_t *node = list->head->next;

    while (node != NULL) {
        if (i == index) {
            break;
        }

        i++;
        node = node->next;
    }

    return node->value;
}

void linkedlist_push_front(linkedlist_t *list, int value)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->next = NULL;
    new_node->value = value;

    node_t *head_node = list->head->next;

    if (head_node != NULL) {
        new_node->next = head_node;
    }

    list->head->next = new_node;
    list->size++;
}

int linkedlist_pop_front(linkedlist_t *list)
{
    if (list->size == 0) {
        printf("error: cannot pop an element from an empty list.\n");
        exit(EXIT_FAILURE);
    }

    node_t *head_node = list->head->next;
    int value = head_node->value;

    head_node = head_node->next;
    list->size--;

    free(head_node);

    return value;
}

void linkedlist_push_back(linkedlist_t *list, int value)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->next = NULL;
    new_node->value = value;

    node_t *last_node = list->head;

    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    last_node->next = new_node;

    list->size++;
}

int linkedlist_pop_back(linkedlist_t *list)
{
    if (list->size == 0) {
        printf("error: cannot pop an element from an empty list.\n");
        exit(EXIT_FAILURE);
    }

    node_t *prev_node = list->head;
    node_t *tail_node = prev_node->next;

    while (tail_node->next != NULL) {
        prev_node = tail_node;
        tail_node = tail_node->next;
    }

    prev_node->next = NULL;
    int value = tail_node->value;

    free(tail_node);
    list->size--;

    return value;
}

int linkedlist_front(linkedlist_t *list)
{
    if (list->size == 0) {
        printf("error: cannot retrieve first element from an empty list.\n");
        exit(EXIT_FAILURE);
    }

    node_t *head_node = list->head->next;
    return head_node->value;
}

int linkedlist_back(linkedlist_t *list)
{
    if (list->size == 0) {
        printf("error: cannot retrieve last element from an empty list.\n");
        exit(EXIT_FAILURE);
    }

    return linkedlist_value_at(list, list->size - 1);
}

void linkedlist_insert(linkedlist_t *list, int index, int value)
{
    linkedlist_validate_index(list, index);

    int i = 0;
    node_t *prev_node = list->head;

    while (i < (index - 1)) {
        prev_node = prev_node->next;
        i++;
    }

    node_t *new_node = malloc(sizeof(node_t));
    new_node->next = prev_node->next;
    new_node->value = value;

    prev_node->next = new_node;

    list->size++;
}

void linkedlist_erase(linkedlist_t *list, int index)
{
    linkedlist_validate_index(list, index);

    int i = 0;
    node_t *prev_node = list->head;
    node_t *erased_node = prev_node->next;

    while (i < (index - 1)) {
        prev_node = erased_node;
        erased_node = erased_node->next;
        i++;
    }

    prev_node->next = erased_node->next;

    free(erased_node);

    list->size--;
}

int linkedlist_value_n_from_end(linkedlist_t *list, int n)
{
    if (n < 1 || n > list->size) {
        printf("error: n must be a number between 1 and %d.\n", list->size);
        exit(EXIT_FAILURE);
    }

    return linkedlist_value_at(list, list->size - n);
}

void linkedlist_remove_value(linkedlist_t *list, int value)
{
    if (list->size == 0) {
        printf("error: cannot remove a value from an empty list.\n");
        exit(EXIT_FAILURE);
    }

    node_t *prev_node = list->head;
    node_t *removed_node = prev_node->next;

    while (removed_node != NULL) {
        if (removed_node->value == value) {
            break;
        }
        prev_node = removed_node;
        removed_node = removed_node->next;
    }

    prev_node->next = removed_node->next;

    free(removed_node);

    list->size--;
}

static node_t *linkedlist_recursive_reverse(linkedlist_t *list, node_t *node)
{
    if (node->next == NULL) {
        list->head->next = node;
    } else {
        node_t *next_node = linkedlist_recursive_reverse(list, node->next);
        next_node->next = node;
    }
    return node;
}

void linkedlist_reverse(linkedlist_t *list)
{
    node_t *tail_node = linkedlist_recursive_reverse(list, list->head->next);
    tail_node->next = NULL;
}

void linkedlist_free(linkedlist_t *list)
{
    node_t *node = list->head;

    while (node != NULL) {
        node_t *next_node = node->next;

        free(node);

        node = next_node;
    }

    free(list);
}
