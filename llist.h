/*
 Linked List implementation
*/

// singly linked list, size is stored in the root element.

#ifndef LLIST_
#define LLIST_ 1

#include <stdlib.h>
#include <stdio.h>

typedef struct linkedlist {
    void * data;
    struct linkedlist * next;
} llist;

llist * linkedlist();
int insert(llist * list, void * data, int position);
void append(llist * list, void * data);
int del(llist * list, int index);
int replace(llist * list, void * data, int index);
int swap(llist * list, int pos1, int pos2);
void * get(llist * list, int index);

void clean(llist * list); // deallocates the list.

int size(llist * list);

// the lack of sort is because you can't exactly sort (void *)'s

#endif
