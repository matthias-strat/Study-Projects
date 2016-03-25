#include <stdio.h>
#include <stdlib.h>

int add(int num, ...)
{
    // Exercise says: no va_list, va_start, ... 
    // This is actually a bad choice since different architectures may
    // store parameters differently on the stack.
    // Just for pointer learning purposes!
    register int sp asm("sp+1");
    printf("%d\n", sp);
    
    return 0;
}

int main()
{
    add(2, 12, 34);
}