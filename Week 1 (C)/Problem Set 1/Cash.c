#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Obtain the value of cash from the user
    float money;
    do
    {
        money = get_float("How much change are you due?: $");
    }
    while(money < 0);

    // Convert dollars into cents
    int cents = round(100 * money);

    // Test
    //printf("Money -> Cents Test: %i\n", cents);

    // Determine the fewest amount of bills and coins necessary to provide exact change
    int billcount = 0;
    int hundredcount = 0;
    int fiftycount = 0;
    int twentycount = 0;
    int tencount = 0;
    int fivecount = 0;
    int onecount = 0;
    int coincount = 0;
    int quartercount = 0;
    int dimecount = 0;
    int nickelcount = 0;
    int pennycount = 0;

    do 
    {
        if (cents >= 10000)
        {
            cents -= 10000;
            billcount++;
            hundredcount++;
        }
    }
    while (cents >= 10000);

    do
    {
        if (cents >= 5000)
        {
            cents -= 5000;
            billcount++;
            fiftycount++;
        }
    }
    while (cents >= 5000);

    do
    {
        if (cents >= 2000)
        {
            cents -= 2000;
            billcount++;
            twentycount++;
        }
    }
    while (cents >= 2000);

    do
    {
        if (cents >= 1000)
        {
            cents -= 1000;
            billcount++;
            tencount++;
        }
    }
    while (cents >= 1000);

    do
    {
        if (cents >= 500)
        {
            cents -= 500;
            billcount++;
            fivecount++;
        }
    }
    while (cents >= 500);

    do
    {
        if (cents >= 100)
        {
            cents -= 100;
            billcount++;
            onecount++;
        }
    }
    while (cents >= 100);

    do
    {
        if (cents >= 25)
        {
            cents -= 25;
            coincount++;
            quartercount++;
        }
    }
    while (cents >= 25);

   // Test
   //printf("Post-Quarters Test: %i\n", cents);

   do
   {
       if (cents >=10)
       {
            cents -= 10;
            coincount++;
            dimecount++;
       }
   }
   while (cents >= 10);

   // Test
   //printf("Post-Dimes Test: %i\n", cents);

   do
   {
       if (cents >= 5)
       {
            cents -= 5;
            coincount++;
            nickelcount++;
       }
   }
   while (cents >= 5);

   // Test
   //printf("Post-Nickels Test: %i\n", cents);

   do
   {
       if (cents >= 1)
       {
            cents -= 1;
            coincount++;
            pennycount++;
       }
   }
   while (cents >= 1);

    // Test
    //printf("Post-Pennies Test: %i\n", cents);

    // Print results to user
    printf("\nThe most efficient change for $%.2f is:\n\n", money);
    if (hundredcount == 1)
    {
        printf("1 hundred-dollar bill\n");
    }
    else if (hundredcount >  1)
    {
        printf("%i hundred-dollar bills\n", hundredcount);
    }

    if (fiftycount == 1)
    {
        printf("1 fifty-dollar bill\n");
    }
    else if (fiftycount > 1)
    {
        printf("%i fifty-dollar bills\n", fiftycount);
    }

    if (twentycount == 1)
    {
       printf("1 twenty-dollar bill\n");
    }
    else if (twentycount > 1)
    {
        printf("%i twenty-dollar bills\n", twentycount);
    }

    if (tencount == 1)
    {
       printf("1 ten-dollar bill\n");
    }
    else if (tencount > 1)
    {
        printf("%i ten-dollar bills\n", tencount);
    }

    if (fivecount == 1)
    {
       printf("1 five-dollar bill\n");
    }
    else if (fivecount > 1)
    {
        printf("%i five-dollar bills\n", fivecount);
    }

    if (onecount == 1)
    {
       printf("1 one-dollar bill\n");
    }
    else if (onecount > 1)
    {
        printf("%i one-dollar bills\n", onecount);
    }

    if (quartercount == 1)
    {
       printf("1 quarter\n");
    }
    else if (quartercount > 1)
    {
        printf("%i quarters\n", quartercount);
    }

    if (dimecount == 1)
    {
       printf("1 dime\n");
    }
    else if (dimecount > 1)
    {
        printf("%i dimes\n", dimecount);
    }

    if (nickelcount == 1)
    {
       printf("1 nickel\n");
    }
    else if (nickelcount > 1)
    {
        printf("%i nickels\n", nickelcount);
    }

    if (pennycount == 1)
    {
       printf("1 penny\n\n");
    }
    else if (pennycount > 1)
    {
        printf("%i pennies\n\n", pennycount);
    }

    printf("Resulting in ");

    if (billcount == 1)
    {
        printf("1 bill ");
    }
    else if (billcount > 1)
    {
        printf("%i bills ", billcount);
    }

    if (coincount == 1)
    {
        printf("and 1 coin.\n");
    }
    else if (coincount > 1)
    {
        printf("and %i coins.\n", coincount);
    }

    //Test
    //printf("Post-Counting Test: %i\n", cents);

}