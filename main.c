#include "sort.h"
#include "essentials.h"

static void test() 
{
    const int arr_size = 6; 
    int a[6/*arr_size*/] = {10,20,130, 22, 11, 21};
    for (int i = 0; i < arr_size; ++i) 
    {
        printf("\n%i", a[i]);
    }
    sortIntArray(COMP_SMALLER, a, (bigptr)6);
    for (int i = 0; i < arr_size; ++i) 
    {
        printf("\n%i", a[i]);
    }
    sortIntArray(COMP_BIGGER, a, (bigptr)6);
    for (int i = 0; i < arr_size; ++i) 
    {
        printf("\n%i", a[i]);
    }

    printf("\n\n");

    char b[13] = "Hello World ";
    char c[13] = "hello world!";
    char d[4] = "hi!";

    printf("\n%s == %s (case sensitive) : %i", b, c, stringComp(b,c));
    printf("\n%s == %s (case insensitive) : %i", b, c, stringCompCaseInsensitive(b,c));
    printf("\n%s == %s (case insensitive) : %i", c, d, stringCompCaseInsensitive(c,d));
    printf("\n%s == %s (case sensitive) : %i\n", c, d, stringComp(c,d));
    printf("\n%s == %s (case sensitive) : %i\n", c, c, stringComp(c,c));
    printf("\n%s == %s (case sensitive) : %i\n", c, c, stringCompCaseInsensitive(c,c));
}

void testList() 
{
    //memptr a = makeListPtr(DATATYPE(long), 10);
    //memptr b = makeListPtr(DATATYPE(long), 10);

    //freeListPtr(a);
    //freeListPtr(b);

    int * c = makeList(DATATYPE(int), 10);
    char * d = makeList(DATATYPE(char), 10);

    c[0] = 10;
    printf("\n%i\n", c[0]);

    freeList(c);
    freeList(d);

    char * e = "i love programming";
    char * f = "   \ti really do\n\ryes\bs    ";
    char * g = stringConcat(e, f);
    printf("%s", g);
    free(g);
}

void testcache() 
{
    cache * a = makeCache(4 * sizeof(char));
    char hello[5] = {'h', 'e', 'l', 'l', 'o'};
    char term = '\0';

    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, hello, 5);
    writeCache(a, &term, 1);

    //works yippeeee

    printf("\n%s\n", (char*)a->data),

    cleanCache(a);
}


int main(int argc, char ** argv) 
{ 
    testcache();
}
