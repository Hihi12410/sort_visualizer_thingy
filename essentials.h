#pragma once

#include "stdlib.h"
#include "stddef.h"
#include "stdio.h"

//Pointer type (no need for uintptr_t)
//Deprecated
typedef unsigned long memptr;

//Array pointer type (no need for bigptr)
typedef unsigned long long bigptr_depr;

//Theoritically biggest object (en.cppreference.com)
typedef typeof(sizeof(0)) bigptr;

//Cache object
typedef struct cache
{
    bigptr len;
    bigptr pointer;
    void* data;
}cache;

//For overflow protection; change when needed
#define SAFELIST_INT_BIGGEST 0xFFFFFF
#define STRINGLEN_MAX_ITER 0xFFFFFFFFFFFFFFFF

//To pass into functions
#define DATATYPE(x) (x*)1
#define TOPOINTER(x) (void*)x

//Memory safe arrays
void*makeListPtr(void * dataType, bigptr startSize);
void freeListPtr(void * list);

void* makeList(void * dataType, bigptr startSize);
void freeList(void * list);

//Maths
int min_int(int a, int b);  
int max_int(int a, int b);

//String manipulation
// 0 : false ; 1 : true
bigptr stringLen(char * str);
int stringComp(char * a, char * b);
int stringCompCaseInsensitive(char * a, char * b);

//Free after use
char * stringConcat(char * a, char * b);


//Caches

#define ERRORCACHE (cache) {-1, -1, NULL}

cache * makeCache (bigptr desiredsize);
int writeCache(cache * cont,void * data, bigptr data_size);
void cleanCache(cache * cont);