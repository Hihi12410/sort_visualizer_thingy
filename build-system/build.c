#include "../essentials.h"
#include "stdio.h"

//TODO : Build-system


char * freeStorage(char * store, int storeSize) 
{
    for (int i =0; i < storeSize; ++i) 
    {
        store[i] = '\0';
    }

    return store;
}

int main(int argc, char ** argv) 
{
    if (argc < 2) return -1;
    
    FILE * file = fopen(argv[1], "r");
    if (file == NULL) return -1;
    
    char c = '\0';
    
    int in_expression = 0;
    char expression = '\0';

    

    while (getc(file))
    {
        if (c == '\'') 
        {
            if (in_expression == 1)
            {
                if (expression == '\'')
                {
                    if (stringCompCaseInsensitive("out", store)) 
                    {

                    }
                }
            }
        }
    }

}