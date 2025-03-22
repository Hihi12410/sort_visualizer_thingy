#include "essentials.h"

//Memory safe array
//Deprecated
inline memptr makeListPtr_depr(void * dataType, bigptr startSize)
{
    void * arr = malloc(sizeof(dataType) * startSize);
    if (arr == NULL) return (memptr) NULL; 
    return (memptr)arr;
}

inline void freeListPtr_depr(memptr list)
{
    free(TOPOINTER(list));
}

//Prod
inline void * makeListPtr(void * dataType, bigptr startSize)
{
    void * arr = malloc(sizeof(dataType) * startSize);
    if (arr == NULL) return NULL; 
    return arr;
}

inline void freeListPtr(void * list)
{
    free(list);
}


inline void* makeList(void * dataType, bigptr startSize)
{
    void * ptr = makeListPtr(dataType, startSize);
    return ptr;
}

inline void freeList(void* list)
{
    free(list);
}


//Maths
//Mostly macros
inline int min_int(int a, int b) 
{
    return (a < b) ? a : b;
}

inline int max_int(int a, int b)
{
    return (a > b) ? a : b;
}

//String comparison
// 0 : false ; 1 : true
inline bigptr stringLen(char * str) 
{
    //Error handling
    if (str == NULL) return 0;
    
    char curr = str[0];
    bigptr i = 0;
    
    //Lazy counting && overflow protection
    while(curr != '\0' && i <= STRINGLEN_MAX_ITER)
    {
        ++i;
        curr = str[i];
    }

    //Possible overflow
    if (i == STRINGLEN_MAX_ITER) return -1;
    return i;
}
inline int stringComp(char * a, char * b) 
{
    bigptr a_size = stringLen(a);
    bigptr b_size = stringLen(b);

    if (a_size != b_size) return 0;
    int x = 1;
    
    //No need for n-1 -> 0x00
    for (int i = 0; i < a_size-1; ++i) 
    {
        if (a[i] != b[i]) 
        {
            x = 0;
        }
    }
    return x;
}
inline int stringCompCaseInsensitive(char * a, char * b) 
{
    bigptr a_size = stringLen(a);
    bigptr b_size = stringLen(b);

    if (a_size != b_size) return 0;
    int x = 1;

    for (int i = 0; i < a_size; ++i) 
    {
        //Padding (a ^ A -> 0x20 (32))
        if ((a[i]^b[i]) != 0x20 && (a[i] ^ b[i]) != 0x0) 
        {
            x = 0;
            break;
        }
    }
    return x;
}

inline char * stringConcat(char * a, char * b) 
{
    if (a == NULL || b == NULL) return NULL;

    int len_a = stringLen(a);
    int len_b = stringLen(b);

    if (len_a + len_b < 1) return NULL;

    char * expo = malloc((len_a + len_b + 1) * sizeof(char));
    if (expo == NULL) return expo;

    int i = 0;
    for ( ; i < len_a; ++i ) expo[i] = a[i];
    for ( ; i < len_b+len_a; ++i ) expo[i] = b[i-len_a];
    expo[len_a+len_b] = '\0';

    return expo;
}


//Caches
inline cache makeCache(bigptr desiredsize)
{
    void*ptr = malloc(desiredsize);
    if (ptr == NULL) return ERRORCACHE;

    return (cache) {desiredsize, 0, ptr};
}
cache writeCache(cache cont,void * data);
cache cleanCache(cache cont);