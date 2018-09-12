#include <stdio.h>
#include <stdlib.h>
#include "DataStructures/LinkedList/LinkedList.h"

int main()
{
    LinkedList l = NewLinkedList(INT_TYPE);

    l->add(l,1,0);
    l->add(l,5,1);
    l->add(l,2,1);

    l->printList(l);

    l->destruct(l);

    return 0;
}
