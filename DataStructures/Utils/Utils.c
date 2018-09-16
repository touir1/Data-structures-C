#include <stdio.h>
#include <stdlib.h>

#include "Utils.h"

/**
* default destruct function for an element
*
* parameters:
* - element(void*): the element to destruct
* - valueType(TYPES_CLASS): the type of the element which is going to be destroyed
*
* returns: void
**/
void _UtilsDefaultDestructElement(void* element, TYPES_CLASS valueType){
    if(valueType == STRING_TYPE || valueType == COMPLEX_TYPE){
        free(element);
    }
}

/**
* default compare function for the elements
*
* parameters:
* - element1(void*): the first element to compare
* - element2(void*): the second element to compare with
*
* returns: int -> 1 if element1 > element2, -1 if element1 < element2 0 otherwise
**/
int _UtilsDefaultCompare(void* element1, void* element2){
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
void _UtilsDefaultPrintElement(void* element, TYPES_CLASS valueType){
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
