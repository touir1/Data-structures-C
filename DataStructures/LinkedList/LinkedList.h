#ifndef _LinkedList_DataStructures
#define _LinkedList_DataStructures

typedef struct _LinkedList* LinkedList;
typedef struct _LinkedListNode* LinkedListNode;

struct _LinkedList {
    LinkedListNode head;

    void (*add)(LinkedList self, void* element, int position);
    void (*remove)(LinkedList self, int position);
    int (*search)(LinkedList self, void* element);
    void* (*get)(LinkedList self,int position);
    void (*destruct)(LinkedList self);
};

typedef struct _LinkedListNode* LinkedListNode;
struct _LinkedListNode {
    void* value;
    LinkedListNode* next;
    LinkedListNode* previous;

};

LinkedList NewLinkedList();
void _LinkedListAdd(LinkedList self, void* element, int position);
void _LinkedListRemove(LinkedList self, int position);
int _LinkedListSearch(LinkedList self, void* element);
void* _LinkedListGet(LinkedList self, int position);
void _LinkedListDestruct(LinkedList self);

#endif // _LinkedList_DataStructures
