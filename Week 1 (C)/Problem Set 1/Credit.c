#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Obtain user's credit card number
    printf("\n");
    long credit;
    do
    {
        credit = get_long("Please enter your credit card number: ");
    }
    while (credit < 1000000000000 || credit > 9999999999999999);

    // Test numbers: 4012888888881881     2223016768739313     4222222222222


    // Convert long into intergers
    int last = credit % 10;

        int secondLastX = (credit % 100) - last;
        int x = secondLastX + last;
    int secondLast = secondLastX / 10;

        int thirdLastX = (credit % 1000) - x;
        x = x + thirdLastX;
    int thirdLast = thirdLastX / 100;

        int fourthLastX = (credit % 10000) - x;
        x = x + fourthLastX;
    int fourthLast = fourthLastX / 1000;

        int fifthLastX = (credit % 100000) - x;
        x = x + fifthLastX;
    int fifthLast = fifthLastX / 10000;

        int sixthLastX = (credit % 1000000) - x;
        x = x + sixthLastX;
    int sixthLast = sixthLastX / 100000;

        int seventhLastX = (credit % 10000000) - x;
        x = x + seventhLastX;
    int seventhLast = seventhLastX / 1000000;

        int eighthLastX = (credit % 100000000) - x;
        x = x + eighthLastX;
    int eighthLast = eighthLastX / 10000000;

        int ninthLastX = (credit % 1000000000) - x;
        x = x + ninthLastX;
    int ninthLast = ninthLastX / 100000000;

        long tenthLastX = (credit % 10000000000) - x;
        x = x + tenthLastX;
    long tenthLast = tenthLastX / 1000000000;

        long eleventhLastX = (credit % 100000000000) - x;
        x = x + eleventhLastX;
    long eleventhLast = eleventhLastX / 10000000000;

        long twelfthLastX = (credit % 1000000000000) - x;
        x = x + twelfthLastX;
    long twelfthLast = twelfthLastX / 100000000000;

        long thirteenthLastY = (credit % 10000000000000);
        long thirteenthLastX = thirteenthLastY - x;
        x = x + thirteenthLastX;
    long thirteenthLast = thirteenthLastX / 1000000000000;

        long fourteenthLast;
        long fourteenthLastX;
        long fourteenthLastY = (credit % 100000000000000);
        if (fourteenthLastY == thirteenthLastY && fourteenthLastY == credit)
        {
            fourteenthLast = 111;
        }
        else
        {
            fourteenthLastX = fourteenthLastY - x;
            x = x + fourteenthLastX;
            fourteenthLast = fourteenthLastX / 10000000000000;
        }

        long fifteenthLast;
        long fifteenthLastX;
        long fifteenthLastY = (credit % 1000000000000000);
        if (fifteenthLastY == fourteenthLastY && fifteenthLastY == credit)
        {
            fifteenthLast = 111;
        }
        else
        {
            fifteenthLastX = fifteenthLastY - x;
            x = x + fifteenthLastX;
            fifteenthLast = fifteenthLastX / 100000000000000;
        }

        long sixteenthLast;
        long sixteenthLastX;
        long sixteenthLastY = (credit % 10000000000000000);
        if (sixteenthLastY == fifteenthLastY && sixteenthLastY == credit)
        {
            sixteenthLast = 111;
        }
        else
        {
            sixteenthLastX = sixteenthLastY - x;
            x = x + sixteenthLastX;
            sixteenthLast = sixteenthLastX / 1000000000000000;
        }

    // Testing
    //printf("\n");
    //printf("*Sixteenth-to-last digit: %li\n", sixteenthLast);
    //printf("*Fifteenth-to-last digit: %li\n", fifteenthLast);
    //printf("Fourteenth-to-last digit: %li\n", fourteenthLast);
    //printf("*Thirteenth-to-last digit: %li\n", thirteenthLast);
    //printf("Twelfth-to-last digit: %li\n", twelfthLast);
    //printf("Eleventh-to-last digit: %li\n", eleventhLast);
    //printf("Tenth-to-last digit: %li\n", tenthLast);
    //printf("Ninth-to-last digit: %i\n", ninthLast);
    //printf("Eighth-to-last digit: %i\n", eighthLast);
    //printf("Seventh-to-last digit: %i\n", seventhLast);
    //printf("Sixth-to-last digit: %i\n", sixthLast);
    //printf("Fifth-to-last digit: %i\n", fifthLast);
    //printf("Fourth-to-last digit: %i\n", fourthLast);
    //printf("Third-to-last digit: %i\n", thirdLast);
    //printf("Second-to-last digit: %i\n", secondLast);
    //printf("Last digit: %i\n\n", last);


    // Calculate checksum
    int sum1 = 0;
    int sum2 = 0;

    int secondLastA;
    int secondLastB;
    int secondLastZ = secondLast * 2;
        if (secondLastZ > 9)
        {
            secondLastA = secondLastZ % 10;
            secondLastB = 1;
        }
        else
        {
            secondLastA = secondLastZ;
            secondLastB = 0;
        }
    int secondLastC = secondLastA + secondLastB;

    int fourthLastA;
    int fourthLastB;
    int fourthLastZ = fourthLast * 2;
        if (fourthLastZ > 9)
        {
            fourthLastA = fourthLastZ % 10;
            fourthLastB = 1;
        }
        else
        {
            fourthLastA = fourthLastZ;
            fourthLastB = 0;
        }
    int fourthLastC = fourthLastA + fourthLastB;

    int sixthLastA;
    int sixthLastB;
    int sixthLastZ = sixthLast * 2;
        if (sixthLastZ > 9)
        {
            sixthLastA = sixthLastZ % 10;
            sixthLastB = 1;
        }
        else
        {
            sixthLastA = sixthLastZ;
            sixthLastB = 0;
        }
    int sixthLastC = sixthLastA + sixthLastB;

    int eighthLastA;
    int eighthLastB;
    int eighthLastZ = eighthLast * 2;
        if (eighthLastZ > 9)
        {
            eighthLastA = eighthLastZ % 10;
            eighthLastB = 1;
        }
        else
        {
            eighthLastA = eighthLastZ;
            eighthLastB = 0;
        }
    int eighthLastC = eighthLastA + eighthLastB;

    int tenthLastA;
    int tenthLastB;
    int tenthLastZ = tenthLast * 2;
        if (tenthLastZ > 9)
        {
            tenthLastA = tenthLastZ % 10;
            tenthLastB = 1;
        }
        else
        {
            tenthLastA = tenthLastZ;
            tenthLastB = 0;
        }
    int tenthLastC = tenthLastA + tenthLastB;

    int twelfthLastA;
    int twelfthLastB;
    int twelfthLastZ = twelfthLast * 2;
        if (twelfthLastZ > 9)
        {
            twelfthLastA = twelfthLastZ % 10;
            twelfthLastB = 1;
        }
        else
        {
            twelfthLastA = twelfthLastZ;
            twelfthLastB = 0;
        }
    int twelfthLastC = twelfthLastA + twelfthLastB;

    int fourteenthLastA;
    int fourteenthLastB;
    int fourteenthLastZ = fourteenthLast * 2;
        if (fourteenthLastZ > 9)
        {
            fourteenthLastA = fourteenthLastZ % 10;
            fourteenthLastB = 1;
        }
        else
        {
            fourteenthLastA = fourteenthLastZ;
            fourteenthLastB = 0;
        }
    int fourteenthLastC = fourteenthLastA + fourteenthLastB;

    int sixteenthLastA;
    int sixteenthLastB;
    int sixteenthLastZ = sixteenthLast * 2;
        if (sixteenthLastZ > 9)
        {
            sixteenthLastA = sixteenthLastZ % 10;
            sixteenthLastB = 1;
        }
        else
        {
            sixteenthLastA = sixteenthLastZ;
            sixteenthLastB = 0;
        }
    int sixteenthLastC = sixteenthLastA + sixteenthLastB;

    if (fourteenthLast == 111)
    {
        sum1 = secondLastC + fourthLastC + sixthLastC + eighthLastC + tenthLastC + twelfthLastC;
        sum2 = last + thirdLast + fifthLast + seventhLast + ninthLast + eleventhLast + thirteenthLast;
    }
    else if (sixteenthLast == 111)
    {
        sum1 = secondLastC + fourthLastC + sixthLastC + eighthLastC + tenthLastC + twelfthLastC + fourteenthLastC;
        sum2 = last + thirdLast + fifthLast + seventhLast + ninthLast + eleventhLast + thirteenthLast + fifteenthLast;
    }
    else
    {
        sum1 = secondLastC + fourthLastC + sixthLastC + eighthLastC + tenthLastC + twelfthLastC + fourteenthLastC + sixteenthLastC;
        sum2 = last + thirdLast + fifthLast + seventhLast + ninthLast + eleventhLast + thirteenthLast + fifteenthLast;
    }

    int sum3 = sum1 + sum2;
    int check = sum3 % 10;

    // Test
    //printf("sum1 = %i\n", sum1);
    //printf("sum2 = %i\n", sum2);
    //printf("sum3 = %i\n", sum3);

    printf("sum3: %i\n", sum3);

    // Check validity of card and if valid, determine whether the card is a MasterCard, Visa, or American Express
    printf("\n");
    if (check != 0)
    {
        printf("Error: You have entered an invalid credit card number (Card number failed checksum test).\n");
    }
    else if (fifteenthLast == 3 && (fourteenthLast == 4 || fourteenthLast == 7) && check == 0 && credit > 100000000000000 && credit < 999999999999999)
    {
        printf("Success. Credit card verified as a valid American Express.\n");
    }
    else if (sixteenthLast == 5 && (fifteenthLast == 1 || fifteenthLast == 2 || fifteenthLast == 3 || fifteenthLast == 4 || fifteenthLast == 5) && check == 0 && credit > 1000000000000000)
    {
        printf("Success. Credit card verified as a valid MasterCard.\n");
    }
    else if (sixteenthLast == 4 && check == 0 && credit > 1000000000000000)
    {
        printf("Success. Credit card verified as a valid Visa.\n");
    }
    else if (thirteenthLast == 4 && check == 0 && credit < 9999999999999)
    {
        printf("Success. Credit card verified as a valid Visa.\n");
    }
    else
    {
        printf("Unexpected error.\n");
    }
    printf("\n");
}