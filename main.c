#include <stdio.h>
#include <stdlib.h>
#include "DataStructures/LinkedList/LinkedList.h"

int main()
{
    LinkedList l = NewLinkedList(INT_TYPE);

    printf("adding 1 to the list at position 0\n");
    l->add(l,1,0);
    printf("adding 2 to the list at position 1\n");
    l->add(l,2,1);
    printf("adding 5 to the list at position 1\n");
    l->add(l,5,1);

    printf("printing list:\n");
    l->printList(l);

    printf("searching for 3 in list: position = %d\n",l->search(l,3));
    printf("searching for 5 in list: position = %d\n",l->search(l,5));

    l->destruct(l);

    return 0;
}
