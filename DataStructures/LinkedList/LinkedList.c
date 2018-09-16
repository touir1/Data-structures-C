#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "../Utils/Utils.h"

/**
* instantiate a new LinkedList
*
* parameters:
* - valuesType(TYPES_CLASS): the type of the data contained in the LinkedList
*
* returns: LinkedList
**/
LinkedList NewLinkedList(TYPES_CLASS valuesType){
    LinkedList self = (LinkedList) malloc(sizeof (struct _LinkedList));

    self->size = 0;
    self->head = NULL;
    self->valuesType = valuesType;

    self->add = & _LinkedListAdd;
    self->removeByIndex = & _LinkedListRemoveByIndex;
    self->search = & _LinkedListSearch;
    self->get = & _LinkedListGet;
    self->printList = & _LinkedListPrintList;
    self->destruct = & _LinkedListDestruct;

    self->compare = & _UtilsDefaultCompare;
    self->printElement = & _UtilsDefaultPrintElement;
    self->destructElement = & _UtilsDefaultDestructElement;

    return self;
}

/**
* adds an element to a LinkedList
*
* parameters:
* - self(LinkedList): the LinkedList where we would add the element
* - element(void*): the element to add to the LinkedList
* - position(int): the position where to add the LinkedList
*
* returns: void
**/
void _LinkedListAdd(LinkedList self, void* element, int position){
    if(position >= 0){
        if(self->head == NULL && position != 0){
            return;
        }
        else if(self->head == NULL){
            LinkedListNode head = (LinkedListNode) malloc(sizeof (struct _LinkedListNode));

            if(self->valuesType != STRING_TYPE && self->valuesType != COMPLEX_TYPE) head->value = element;
            else head->value = & element;

            head->next = NULL;
            head->previous = NULL;

            self->head = head;

            self->size += 1;
        }
        else if(position <= self->size){
            LinkedListNode newNode = (LinkedListNode) malloc(sizeof (struct _LinkedListNode));

            if(self->valuesType != STRING_TYPE && self->valuesType != COMPLEX_TYPE) newNode->value = element;
            else newNode->value = & element;

            if(position == 0){
                newNode->next = self->head;
                newNode->previous = NULL;

                self->head = newNode;
            }
            else if(position == self->size){
                LinkedListNode last = self->head;
                while(last->next != NULL){
                    last = last->next;
                }
                newNode->previous = last;
                newNode->next = NULL;

                last->next = newNode;
            }
            else{
                LinkedListNode last = self->head;
                int i=0;
                for(i=1;i<position;i++){
                    last = last->next;
                }
                newNode->next = last->next;
                newNode->previous = last;
                last->next->previous = newNode;

                last->next = newNode;
            }

            self->size += 1;
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

/**
* removes an element from a LinkedList using its index
*
* parameters:
* - self(LinkedList): the LinkedList from where we are going to remove the element
* - position(int): the index of the element in the LinkedList
*
* returns: void
**/
void _LinkedListRemoveByIndex(LinkedList self, int position){
    if(self->size != 0 && position < self->size){
        LinkedListNode node = self->head;
        int i=0;
        while(i<position){
            node = node->next;
            i++;
        }

        if(node->previous != NULL){
            node->previous->next = node->next;
        }
        if(node->next != NULL){
            node->next->previous = node->previous;
        }
        if(position == 0){
            self->head = node->next;
        }

        self->destructElement(node->value, self->valuesType);
        node->previous = NULL;
        node->next = NULL;
        free(node);

        self->size -= 1;
    }
}

/**
* searches an element in a LinkedList
*
* parameters:
* - self(LinkedList): the LinkedList where we are going to look for the element
* - element(void*): the element we are looking for in the LinkedList
*
* returns: int: the position of the element in the LinkedList
**/
int _LinkedListSearch(LinkedList self, void* element){
    if(self->size != 0){
        LinkedListNode node = self->head;
        int index = 0;
        do{
            if(self->compare(element,node->value) == 0){
                return index;
            }
            node = node->next;
            index++;
        }
        while(node != NULL);
    }
    return -1;
}

void* _LinkedListGet(LinkedList self, int position){
    //TODO
    printf("Get LinkedList");
    return NULL;
}

/**
* function which destroys the LinkedList
*
* parameters:
* - self(LinkedList): the LinkedList where we would add the element
*
* returns: void
**/
void _LinkedListDestruct(LinkedList self){
    if(self->size > 0){
        LinkedListNode node = self->head;

        if(self->valuesType != STRING_TYPE && self->valuesType != COMPLEX_TYPE) self->destructElement(& node->value,self->valuesType);
        else self->destructElement(node->value,self->valuesType);

        while(node->next != NULL){
            node = node->next;

            if(self->valuesType != STRING_TYPE && self->valuesType != COMPLEX_TYPE) self->destructElement(& node->value,self->valuesType);
            else self->destructElement(node->value,self->valuesType);

            free(node->previous);
        }

        free(node);

        self->size = 0;
        self->head = NULL;

        self->add = NULL;
        self->removeByIndex = NULL;
        self->search = NULL;
        self->get = NULL;
        self->printList = NULL;
        self->destruct = NULL;

        self->compare = NULL;
        self->printElement = NULL;
        self->destructElement = NULL;
    }

    free(self);
}

/**
* prints out the content of the LinkedList
*
* parameters:
* - self(LinkedList): the LinkedList which is going to be printed
*
* returns: void
**/
void _LinkedListPrintList(LinkedList self){
    if(self->size >0){
        printf("[");

        LinkedListNode node = self->head;
        self->printElement(node->value,self->valuesType);

        while(node->next != NULL){
            node = node->next;
            printf(", ");
            self->printElement(node->value,self->valuesType);
        }

        printf("]\n");
    }
    else{
        printf("[]\n");
    }
}

/**
* a function which tests all the functions in the LinkedList structure
*
* returns: void
**/
void _LinkedListTest(){

    printf("create the list\n");
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

    printf("removing the element at index 1 from the list\n");
    l->removeByIndex(l,1);

    printf("printing list:\n");
    l->printList(l);

    printf("destruct the list\n");
    l->destruct(l);
}
