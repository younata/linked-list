/*
 A linked list implementation in C.
*/

#include "llist.h"

llist * linkedlist()
{
    llist * head = calloc(1, sizeof(llist));
    int * size = calloc(1, sizeof(int));
    *size = 0;
    head->data = size;
    head->next = NULL;
    return head;
}

void add(llist * list, void * data)
{
    llist * foo = list;
    while (foo->next != NULL) {
        foo = foo->next;
    }
    llist * new = calloc(1, sizeof(llist));
    new->data = data;
    llist * last = foo;
    last->next = new;
    new->next = NULL;
    *(int *)list->data += 1;
}

int del(llist * list, int index)
{
    int size = *(int *)list->data;
    if (index > size || index < 0) {
        fprintf(stderr, "Attempting to delete element outside range of list.\n");
        return 1;
    } else if (index == 0) {
        fprintf(stderr, "Attempting to delete root list element.\n");
        return 2;
    }
    int i = 0;
    llist * foo = list;
    for (;i < index; i++) {
        foo = foo->next;
    }
    llist * toDelete = list->next;
    list->next = toDelete->next;
    free(toDelete);
    toDelete = NULL;
    *(int *)list->data -= 1;
    return 0;
}

int replace(llist * list, void * data, int index)
{
    int size = *(int *)list->data;
    if (index > size || index < 0) {
        fprintf(stderr, "Attempting to replace element outside range of list.\n");
        return 1;
    } else if (index == 0) {
        fprintf(stderr, "Attempting to replace root list element.\n");
        return 2;
    }
    int i = 0;
    llist * foo = list;
    for (;i <= index; i++) {
        foo = foo->next;
    }
    if (foo->data != NULL) {
        free(foo->data);
        foo->data = NULL;
    }
    foo->data = data;
    return 0;
}

void * get(llist * list, int index)
{
    int size = *(int *)list->data;
    if (index > size || index < 0) {
        fprintf(stderr, "Attempting to get element outside range of list.\n");
        return NULL;
    }
    int i = 0;
    llist * foo = list;
    for (;i <= index; i++) {
        foo = foo->next;
    }
    return foo->data;
}

void clean(llist * list)
{
    llist * next = list->next;;
    while (next != NULL) {
        free(list);
        list = next;
        next = list->next;
    }
    free(list);
}

int size(llist * list)
{
    return *(int *)list->data;
}
