#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Obtain values from user
    int x = get_int("What is the value of X?: ");
    int y = get_int("What is the value of Y?: ");


    // Compare the obtained values
    if (x > y)
    {
        printf ("X is greater than Y\n");
    }
    else if (x < y)
    {
        printf ("X is less than Y\n");
    }
    else
    {
        printf ("X is equal to Y\n");
    }
}