#ifndef _ArrayList_DataStructures
#define _ArrayList_DataStructures

#include "../Utils/Utils.h"

typedef struct _ArrayList* ArrayList;
struct _ArrayList{
    void** elements;
    int size;
    int capacity;
    TYPES_CLASS valuesType;

    // functions
    void (*add)(ArrayList self, void* element, int position);
    void (*removeByIndex)(ArrayList self, int position);
    int (*search)(ArrayList self, void* element);
    void* (*get)(ArrayList self,int position);
    void (*set)(ArrayList self, void* element, int position);
    void (*printList)(ArrayList self);
    void (*destruct)(ArrayList self);

    // utility functions
    int (*compare)(void* element1, void* element2);
    void (*printElement)(void* element, TYPES_CLASS valueType);
    void (*destructElement)(void* element, TYPES_CLASS valueType);
};

ArrayList NewArrayList(TYPES_CLASS valuesType);

void _ArrayListAdd(ArrayList self, void* element, int position);
void _ArrayListRemoveByIndex(ArrayList self, int position);
int _ArrayListSearch(ArrayList self, void* element);
void* _ArrayListGet(ArrayList self, int position);
void _ArrayListSet(ArrayList self, void* element, int position);
void _ArrayListPrintList(ArrayList self);
void _ArrayListDestruct(ArrayList self);

void _ArrayListTest();
#endif // _ArrayList_DataStructures
