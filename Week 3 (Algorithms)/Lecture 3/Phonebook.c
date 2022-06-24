#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
string name;
string number;
}
entry;

int const NUMBER = 2;

int main(void)
{
    entry people[NUMBER];

    people[0].name = "Michelle";
    people[0].number = "+1-765-771-0100";

    people[1].name = "Zach";
    people[1].number = "+1-513-850-3668";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "Zach") == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}