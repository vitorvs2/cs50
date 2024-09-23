#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardnumber = get_long("Number: ");
    long number = cardnumber;
    int count = 0;
    while (number != 0)
    {
        // Loop that stores the count of digits for the given number
        count++;
        number /= 10;
        // Number is divided by 10 until the resulting number be less than 1
    }
    // printf("digits: %i\n",count);

    number = cardnumber;
    int digit, step1 = 0, step2 = 0, first = 0, second = 0;

    for (int i = 1; i <= count; i++)
    {

        digit = number % 10;
        if (i == count - 1)
        {
            second = digit;
        }
        else
        {
            first = digit;
        }

        number /= 10;

        if (i % 2 == 0)
        {
            // printf("| %i x 2 = ", digit);
            if (digit * 2 >= 10)
            {
                // printf("1 + %i ", (digit * 2) % 10);
                step1 += 1 + ((digit * 2) % 10);
            }
            else
            {
                // printf("%i ",digit * 2);
                step1 += digit * 2;
            }
        }
        else
        {
            // printf("| %i ", digit);
            step2 += digit;
        }
        first = digit;
    }
    // printf("\nstep1: %i,", step1);
    // printf("\nstep2: %i,", step2);

    if ((step1 + step2) % 10 == 0)
    {
        if (first == 3 && (second == 4 || second == 7) && count == 15)
        {
            printf("AMEX\n");
        }
        else
        {
            if (first == 4 && (count == 13 || count == 16))
            {
                printf("VISA\n");
            }
            else
            {
                if (first == 5 &&
                    (second == 1 || second == 2 || second == 3 || second == 4 || second == 5) &&
                    count == 16)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
        // printf("\nsum: %i, card is legit\n", step1 + step2);
    }
    else
    {
        printf("INVALID\n");
        // printf("\nsum: %i, card is not legit\n", step1 + step2);
    }
    // printf("\nstarting digit: %i", first);
}
