#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

LinkedList NewLinkedList(){
    LinkedList self = (LinkedList) malloc(sizeof (struct _LinkedList));

    self->add = & _LinkedListAdd;
    self->remove = & _LinkedListRemove;
    self->search = & _LinkedListSearch;
    self->get = & _LinkedListGet;
    self->destruct = & _LinkedListDestruct;

    return self;
}

void _LinkedListAdd(LinkedList self, void* element, int position){
    //TODO
    printf("Add LinkedList");
}

void _LinkedListRemove(LinkedList self, int position){
    //TODO
    printf("Remove LinkedList");
}

int _LinkedListSearch(LinkedList self, void* element){
    //TODO
    printf("Search LinkedList");
    return 0;
}

void* _LinkedListGet(LinkedList self, int position){
    //TODO
    printf("Get LinkedList");
    return NULL;
}

void _LinkedListDestruct(LinkedList self){
    //TODO
    printf("Destruct LinkedList");
    free(self);
}
