#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (int argc, string argv[])
{
    // Ensure only one command line argument was entered
    if (argc != 2)
    {
        printf("Error - Please use format: ./Substitution key\n");
        return 1;
    }

    // Ensure key is only 26 characters
    int n = strlen(argv[1]);

    if (n != 26)
    {
        printf("Error - Key must contain 26 characters\n");
        return 1;
    }

    // Iterate over each character in key to check validity
    for (int i = 0; i < n; i++)
    {
        // Ensure key contains only alphabetic characters
        if (argv[1][i] < 65 || argv[1][i] > 122 || (argv[1][i] > 90 && argv[1][i] < 97))
        {
            printf("Error - Key must contain only alphabetic characters\n");
            return 1;
        }

        // Ensure key contains no repeated characters
        for (int j = 0; j < i; j++)
        {
            if (argv[1][i] == argv[1][j] || argv[1][i] == argv[1][j] + 32 || argv[1][i] == argv[1][j] - 32)
            {
                printf("Error - Key must not contain repeated characters\n");
                return 1;
            }
        }
    }

    // Obtain plaintext from user
    string plain = get_string("Enter plaintext: ");

    // Encipher plaintext and print generated ciphertext
    int m = strlen(plain);
    string key = argv[1];

    printf("Ciphertext: ");

    for (int i = 0; i < m; i++)
    {
        if (plain[i] > 64 && plain[i] < 91)
        {
            int c = plain[i] - 65;
            if (key[c] > 64 && key[c] < 91)
            {
                printf("%c", key[c]);
            }
            else if (key[c] > 96 && key[c] < 123)
            {
                printf("%c", key[c] - 32);
            }
        }
        else if (plain[i] > 96 && plain[i] < 123)
        {
            int c = plain[i] - 97;
            if (key[c] > 64 && key[c] < 91)
            {
                printf("%c", key[c] + 32);
            }
            else if (key[c] > 96 && key[c] < 123)
            {
                printf("%c", key[c]);
            }
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}