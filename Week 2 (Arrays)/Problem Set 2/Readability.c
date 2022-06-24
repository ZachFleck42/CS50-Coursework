#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    // Obtain text from user
    string s = get_string("Text: ");

    int charCount = 0;
    int wordCount = 0;
    int senCount = 0;
    int n = strlen(s);
    printf("\n");

    // Count letters, words, and sentences
    if (n > 0)
    {
        wordCount++;
    }

    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            charCount++;
        }
        else if (s[i] == ' ')
        {
            wordCount++;
        }
        else if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            senCount++;
        }
    }

    // Testing
    printf("Letters: %i\n", charCount);
    printf("Words: %i\n", wordCount);
    printf("Sentences: %i\n", senCount);


    // Initialize values for final calculation
    float wordsX = 100 / (float) wordCount;
    float charX = wordsX * charCount;
    float senX = wordsX * senCount;

    // Testing
    printf("Letters per 100 words: %.2f\n", charX);
    printf("Sentences per 100 words: %.2f\n", senX);
    printf("\n");


    // Calculate readability sore and print results
    float index = (0.0588 * charX) - (0.296 * senX) - 15.8;

    if (index < 1)
    {
        printf("Text determined to be at Before Grade 1 reading level.\n");
    }
    else if (index >= 16)
    {
        printf("Text determined to be at Grade 16+ reading level.\n");
    }
    else
    {
        printf("Text determined to be at Grade %.f reading level.\n", round(index));
    }
}