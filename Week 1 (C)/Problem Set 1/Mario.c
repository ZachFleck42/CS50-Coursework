#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for height of pyramid (between 1 and 8)
    int height;
    do
    {
        height = get_int("What height should the pyramids be? (Enter a value between 1 and 8): ");
    }
    while(height <= 0 || height >= 9);
    printf("\n");

    // Create the pyramids
    int blank = height - 1;
    int block = 1;

    for (int i = 0; i < height; i++)
        {
            for (int a = 0; a < blank; a++)
                {
                    printf(" ");
                }
            for (int b = 0; b < block; b++)
                {
                    printf("#");
                }
            printf("  ");
            for (int c = 0; c < block; c++)
                {
                    printf("#");
                }
            for (int d = 0; d < blank; d++)
                {
                    printf(" ");
                }
            printf("\n");
            blank--;
            block++;
        }
}