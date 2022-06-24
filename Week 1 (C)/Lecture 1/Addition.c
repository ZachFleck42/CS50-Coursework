#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("What is the value of x?: ");
    int y = get_int("What is the value of y?: ");
    
    printf("The value of x + y is: %i \n", x+y);
}