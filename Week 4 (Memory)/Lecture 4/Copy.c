#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* s = get_string("s: ");

    char* t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    /*
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        // *(t + i) = *(s + i);
        t[i] = s[i];
    }
    */

    strcpy(t, s);

    // *t = toupper(*t);
    t[0] = toupper(t[0]);

    printf("t: %s\n", t);

    free(t);
}