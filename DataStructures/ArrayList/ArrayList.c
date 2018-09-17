#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "../Utils/Utils.h"

#define _ARRAYLIST_MIN_SIZE 2
#define _ARRAYLIST_MAX_SIZE 4_294_967_295

/**
* instantiate a new ArrayList
*
* parameters:
* - valuesType(TYPES_CLASS): the type of the data contained in the ArrayList
*
* returns: ArrayList
**/
ArrayList NewArrayList(TYPES_CLASS valuesType){
    ArrayList self = (ArrayList) malloc(sizeof (struct _ArrayList));

    self->size = 0;
    self->capacity = _ARRAYLIST_MIN_SIZE;
    self->elements = (void**) malloc(self->capacity * sizeof(void*));
    self->valuesType = valuesType;

    self->add = & _ArrayListAdd;
    self->removeByIndex = & _ArrayListRemoveByIndex;
    self->search = & _ArrayListSearch;
    self->get = & _ArrayListGet;
    self->set = & _ArrayListSet;
    self->printList = & _ArrayListPrintList;
    self->destruct = & _ArrayListDestruct;

    self->compare = & _UtilsDefaultCompare;
    self->printElement = & _UtilsDefaultPrintElement;
    self->destructElement = & _UtilsDefaultDestructElement;

    return self;
}

/**
* adds an element to a ArrayList
*
* parameters:
* - self(ArrayList): the ArrayList where we would add the element
* - element(void*): the element to add to the ArrayList
* - position(int): the position where to add the ArrayList
*
* returns: void
**/
void _ArrayListAdd(ArrayList self, void* element, int position){
    //TODO
    printf("ArrayListAdd function\n");
}

/**
* removes an element from a ArrayList using its index
*
* parameters:
* - self(ArrayList): the ArrayList from where we are going to remove the element
* - position(int): the index of the element in the ArrayList
*
* returns: void
**/
void _ArrayListRemoveByIndex(ArrayList self, int position){
    //TODO
    printf("ArrayListRemoveByIndex function\n");
}

/**
* searches an element in a ArrayList
*
* parameters:
* - self(ArrayList): the ArrayList where we are going to look for the element
* - element(void*): the element we are looking for in the ArrayList
*
* returns: int: the position of the element in the ArrayList
**/
int _ArrayListSearch(ArrayList self, void* element){
    //TODO
    printf("ArrayListSearch function\n");
    return 0;
}

/**
* gets an element by index from a ArrayList
*
* parameters:
* - self(ArrayList): the ArrayList where we are going to look for the element
* - position(int): the position of the element we are looking for in the ArrayList
*
* returns: void*: the element we are looking for
**/
void* _ArrayListGet(ArrayList self, int position){
    //TODO
    printf("ArrayListGet function\n");
    return NULL;
}

/**
* sets an element by index in a ArrayList
*
* parameters:
* - self(ArrayList): the ArrayList where we are going to add the element
* - element(void*): the element we are going to add
* - position(int): the position in which we are going to add the element
*
* returns: void
**/
void _ArrayListSet(ArrayList self, void* element, int position){
    //TODO
    printf("ArrayListSet function\n");
}

/**
* function which destroys the ArrayList
*
* parameters:
* - self(ArrayList): the ArrayList where we would add the element
*
* returns: void
**/
void _ArrayListDestruct(ArrayList self){
    //TODO
    printf("ArrayListDestruct function\n");
}

/**
* prints out the content of the ArrayList
*
* parameters:
* - self(ArrayList): the ArrayList which is going to be printed
*
* returns: void
**/
void _ArrayListPrintList(ArrayList self){
    //TODO
    printf("ArrayListPrintList function\n");
}

/**
* a function which tests all the functions in the ArrayList structure
*
* returns: void
**/
void _ArrayListTest(){

    printf("create the list\n");
    ArrayList l = NewArrayList(INT_TYPE);

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

    printf("getting element in index 1: %d\n",l->get(l,1));

    printf("setting the value 11 in the element in index 2\n");
    l->set(l,11,2);

    printf("printing list:\n");
    l->printList(l);

    printf("removing the element at index 1 from the list\n");
    l->removeByIndex(l,1);

    printf("printing list:\n");
    l->printList(l);

    printf("destruct the list\n");
    l->destruct(l);
}
