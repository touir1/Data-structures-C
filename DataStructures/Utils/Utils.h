#ifndef _Utils_DataStructures
#define _Utils_DataStructures

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

int _UtilsDefaultCompare(void* element1, void* element2);
void _UtilsDefaultPrintElement(void* element, TYPES_CLASS valueType);
void _UtilsDefaultDestructElement(void* element, TYPES_CLASS valueType);

#endif // _Utils_DataStructures
