#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, string argv[])
{
    // Ensure the user has entered a positive interger as the command argument
    if (argc != 2)
    {
        printf("Error - Please use format: ./Caesar key\n");
        return 1;
    }


    // Ensure the user has entered a positive interger for the cipher key
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < 48 || argv[1][i] > 57)
        {
            printf("Error - Please enter a positive interger for cipher key\n");
            return 1;
        }
    }


    // Get plaintext from the user
    string s = get_string("Enter plaintext: ");


    // Iterate over each character in provided plaintext, apply the provided key (if applicable) to each character, and print out generated ciphertext
    int key = atoi(argv[1]) % 26;

    // Test
    //printf("argv: %s\n", argv[1]);
    //printf("key: %i\n", key);

    printf("Ciphertext: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if ((s[i] > 64) && (s[i] < 91))
        {
            if ((s[i] + key) > 90)
            {
                printf("%c", (s[i] + (key - 26)));
            }
            else
            {
                printf("%c", (s[i] + key));
            }
        }
        else if ((s[i] > 96) && (s[i] < 123))
        {
            if ((s[i] + key) > 122)
            {
                printf("%c", (s[i] + (key - 26)));
            }
            else
            {
                printf("%c", (s[i] + key));
            }
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}