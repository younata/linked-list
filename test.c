#include "llist.h"

void print(llist * list);

int main(int argc, char *argv[])
{
    llist * list = linkedlist();
    int i;
    for (i = 0; i < 10; i++) {
        int * foo = calloc(1, sizeof(int));
        *foo = i;
        add(list, foo);
    }
    for (i = 0; i < size(list); i += 3) {
        del(list, i);
    }
    int * foo = calloc(1, sizeof(int));
    *foo = 5;
    replace(list, foo, 2);
    print(list);
    clean(list);
    list = NULL;
}

void print(llist * list)
{
    llist * foo = list->next;
    printf("size: %d\n", *(int *)list->data);
    while (foo != NULL) {
        printf("%d ", *(int *)foo->data);
        foo = foo->next;
    }
    printf("\n");
}
