#ifndef _LinkedList_DataStructures
#define _LinkedList_DataStructures

#include "../Utils/Utils.h"

typedef struct _LinkedList* LinkedList;
typedef struct _LinkedListNode* LinkedListNode;

struct _LinkedList {
    // attributes
    LinkedListNode head;
    int size;
    TYPES_CLASS valuesType;

    // functions
    void (*add)(LinkedList self, void* element, int position);
    void (*removeByIndex)(LinkedList self, int position);
    int (*search)(LinkedList self, void* element);
    void* (*get)(LinkedList self,int position);
    void (*printList)(LinkedList self);
    void (*destruct)(LinkedList self);

    // utility functions
    int (*compare)(void* element1, void* element2);
    void (*printElement)(void* element, TYPES_CLASS valueType);
    void (*destructElement)(void* element, TYPES_CLASS valueType);
};

typedef struct _LinkedListNode* LinkedListNode;
struct _LinkedListNode {
    // attributes
    void* value;
    LinkedListNode next;
    LinkedListNode previous;

};

LinkedList NewLinkedList(TYPES_CLASS valuesType);

void _LinkedListAdd(LinkedList self, void* element, int position);
void _LinkedListRemoveByIndex(LinkedList self, int position);
int _LinkedListSearch(LinkedList self, void* element);
void* _LinkedListGet(LinkedList self, int position);
void _LinkedListPrintList(LinkedList self);
void _LinkedListDestruct(LinkedList self);

void _LinkedListTest();
#endif // _LinkedList_DataStructures
