#include <stdio.h>
int main() 
{
    char a = 'a';
    char A = 'A';

    printf("%c ^ %c = %i", a, A, a^A);
    
    a = 'b';
    A = 'B';
    
    printf("\n%c ^ %c = %i", a, A, a^A);
    
    a = 'c';
    A = 'C';
    
    printf("\n%c ^ %c = %i", a, A, a^A);
    
    //0x2 padding

    return 0;
}