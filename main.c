#include "modules/sort.h"
#include "modules/essentials.h"

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
    cache * a = makeCache(4 * sizeof(char)); // Allocates space for 4 characters
    char term = '\0';
    char evil_hello[9] = {'e','v','i','l','h', 'e', 'l', 'l', 'o'};

    // Writing "abcd" 100 times to the cache
    for (int i = 0; i < 100; ++i) {
        writeCache(a, "\0\0abcd\0", 8); // Writes 8 bytes each time
    }
    shrinkCacheNonPreserve(a); // Shrinks the cache
    writeCache(a, &term, 1); // Writes the null terminator
    printf("\n%s\n", (char*)a->data); // Attempts to print the cached data

    cleanCache(a); // Clears the cache
    writeCache(a, evil_hello, 9); // Writes "evilhello" to the cache
    writeCache(a, &term, 1); // Writes the null terminator
    printf("\n%s\n", (char*)a->data); // Attempts to print the cached data

    freeCache(a); // Frees the cache
}

int main(int argc, char ** argv) 
{ 
    testcache();
}
