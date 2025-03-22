#include "essentials.h"

#define COMP_SMALLER "<"
#define COMP_BIGGER ">"
#define COMP_EQU "="            //Len : 2
#define COMP_SMALLER_EQU "<="   //Len : 3
#define COMP_BIGGER_EQU ">="

//Sorts the array. Returns -1 on faulty input
int sortIntArray(char * mode, int*list, bigptr size);
int sortIntArrayStepByStep();