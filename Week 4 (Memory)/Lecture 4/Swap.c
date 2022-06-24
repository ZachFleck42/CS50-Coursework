#include <stdio.h>

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);

    swap(x, y);

    printf("x is %i, y is %i\n", x, y);
}