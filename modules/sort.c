#include "sort.h"

//Primitives and conditionals
void __sort_int_arr_smaller(int *list, bigptr size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = i; j < size; ++j) 
        {
            if (list[i] < list[j])
            {
                //XOR trick
                list[i] ^= list[j];
                list[j] ^= list[i];
                list[i] ^= list[j];
            }
        }
    }
}
void __sort_int_arr_bigger(int *list, bigptr size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = i; j < size; ++j) 
        {
            if (list[i] > list[j])
            {
                //XOR trick
                list[i] ^= list[j];
                list[j] ^= list[i];
                list[i] ^= list[j];
            }
        }
    }
}

//As defined in header file
inline int sortIntArray(char * mode, int * list,bigptr size) 
{
    if (mode == NULL || list == NULL || size < 1) return -1;
    if (mode[0] == COMP_SMALLER[0])
    {
        __sort_int_arr_smaller(list, size);
        return 0;
    }
    else if (mode[0] == COMP_BIGGER[0])
    {
        __sort_int_arr_bigger(list, size);
        return 0;
    }
    else
    {
        return -1;
    }
}
