#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Introduce the program
    printf("This program calculates the amount of time (in years) required for a population to reach a specified size, given that each year n/3 citizens are born and n/4 citizens die\n\n");

    // Prompt user for start size
    int start;
    int end;
    do
    {
        start = get_int("What is the start population size? (Value must be greater than 9): ");
    }
    while (start < 9);

    // Prompt user for end size
    do
    {
        end = get_int("What is the end population size? (Value must be greater than start population size): \n");
    }
    while (end < start);

    // Calculate number of years until threshold is reached
    int years = 0;
    int pop = start;
    do
        {
            int dead = pop / 4;
            int born = pop / 3;
            pop = pop + born - dead;
            years ++;
        }
    while (pop <= end);

    // Print the calculated number of years
    printf("It will take %i years for the population to go from %i to %i.\n", years, start, end);

}