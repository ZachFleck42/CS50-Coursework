#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get width and height from user
    int width = get_int("What is the width of your block?: ");
    int height = get_int("What is the height of your block?: ");
    printf("\n");

    // Create and print the custom brick
    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
                {
                    printf("#");
                }
            printf("\n");
        }
}