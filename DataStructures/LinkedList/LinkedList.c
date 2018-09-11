#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

/**
* instanciate a new LinkedList
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
    self->remove = & _LinkedListRemove;
    self->search = & _LinkedListSearch;
    self->get = & _LinkedListGet;
    self->printList = & _LinkedListPrintList;
    self->destruct = & _LinkedListDestruct;

    self->compare = & _LinkedListDefaultCompare;
    self->printElement = & _LinkedListDefaultPrintElement;

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

/**
* default compare function for the LinkedList elements
*
* parameters:
* - element1(void*): the first element to compare
* - element2(void*): the second element to compare with
*
* returns: int -> 1 if element1 > element2, -1 if element1 < element2 0 otherwise
**/
int _LinkedListDefaultCompare(void* element1, void* element2){
    if(element1 > element2) return 1;
    if(element1 < element2) return -1;
    return 0;
}

/**
* prints out an element
*
* parameters:
* - element(void*): the element which is going to be printed
* - valueType(TYPES_CLASS): the type of the element which is going to be printed
*
* returns: void
**/
void _LinkedListDefaultPrintElement(void* element, TYPES_CLASS valueType){
    switch(valueType){
    case INT_TYPE:
        printf("%d",element); break;
    case UNSIGNED_INT_TYPE:
        printf("%u",element); break;
    case LONG_TYPE:
        printf("%l",element); break;
    case UNSIGNED_LONG_TYPE:
        printf("%lu",element); break;
    case LONG_LONG_TYPE:
        printf("%lld",element); break;
    case UNSIGNED_LONG_LONG_TYPE:
        printf("%llu",element); break;
    case FLOAT_TYPE:
        printf("%f",element); break;
    case CHAR_TYPE:
        printf("%c",element); break;
    case STRING_TYPE:
        printf("%s",element); break;
    case COMPLEX_TYPE:
        printf("%p",(void*) &element); break;
    default:
        printf("%p",(void*) &element); break;
    }
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
