#include <stdio.h>
#include <stdlib.h>
#include "DataStructures/LinkedList/LinkedList.h"

void testFunction();

int main()
{
    testFunction();
    return 0;
}

void testFunction(){
    printf("=========== LinkedList ===========\n");
    _LinkedListTest();
    printf("==================================\n");
    printf("=========== ArrayList  ===========\n");
    _ArrayListTest();
    printf("==================================\n");
}
