#ifndef _LinkedList_DataStructures
#define _LinkedList_DataStructures

typedef enum{
    INT_TYPE,
    UNSIGNED_INT_TYPE,
    LONG_TYPE,
    UNSIGNED_LONG_TYPE,
    LONG_LONG_TYPE,
    UNSIGNED_LONG_LONG_TYPE,
    FLOAT_TYPE,
    CHAR_TYPE,
    STRING_TYPE,
    COMPLEX_TYPE
} TYPES_CLASS;

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
    void (*destructElement)(void* element, TYPES_CLASS valueType);

    // utility functions
    int (*compare)(void* element1, void* element2);
    void (*printElement)(void* element, TYPES_CLASS valueType);
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

int _LinkedListDefaultCompare(void* element1, void* element2);
void _LinkedListDefaultPrintElement(void* element, TYPES_CLASS valueType);
void _LinkedListDefaultDestructElement(void* element, TYPES_CLASS valueType);

void _LinkedListTest();
#endif // _LinkedList_DataStructures
