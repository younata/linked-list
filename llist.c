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

int insert(llist * list, void * data, int position)
{
    int size = *(int *)list->data;
    if (position > size || position < 0) {
        fprintf(stderr, "Error: insert position out of range\n");
        return 1;
    } else if (position == 0) {
        fprintf(stderr, "Error: inserting into root element not allowed\n");
        return 2;
    }
    llist * foo = ;
    while (--position > 0) {
        foo = foo->next;
    }
    llist * new = calloc(1, sizeof(llist));
    new->data = data;
    new->next = foo->next;
    foo->next = new;
    return 0;
}

void append(llist * list, void * data)
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
        fprintf(stderr, "Error: Attempting to replace element outside range of list.\n");
        return 1;
    } else if (index == 0) {
        fprintf(stderr, "Error: Attempting to replace root list element.\n");
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
    *(int *)list->data++;
    return 0;
}

int swap(llist * list, int pos1, int pos2)
{
    int size = *(int *)list->data;
    if ((pos1 > size) || (pos2 > size) || (pos1 < 0) || (pos2 < 0)) {
        fprintf(stderr, "Error: Out of range\n");
        return 1;
    } else if ((pos1 == 0) || (pos2 == 0)) {
        fprintf(stderr, "Error: attempting to swap with root element\n");
        return 2;
    }
    void * val1 = get(list, pos1);
    void * val2 = get(list, pos2);
    int ret1 = replace(list, val1, pos2);
    int ret2 = replace(list, val2, pos1);
    if (ret1 + ret2 != 0) {
        fprintf(stderr, "Fatal Error: This should not happen.\n");
        exit(1);
    }
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
