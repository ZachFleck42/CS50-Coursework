#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char x = get_char("Do you agree?: ");

    if (x == 'y' || x == 'Y')
    {
        printf("Agreed\n");
    }
    else if (x == 'n' || x == 'N')
    {
        printf("Not agreed\n");
    }
    else
    {
        printf("Error. Please answer with Y/N");
    }
}