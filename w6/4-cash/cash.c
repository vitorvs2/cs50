#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change = 0;
    while (change == 0 || change < 0)
    {
        change = get_int("Change owed: ");
    }

    int quarters = change / 25;
    change = change % 25;

    int dimes = change / 10;
    change = change % 10;

    int nickels = change / 5;
    change = change % 5;

    int pennies = change / 1;

    // printf ("quarters:  %i\n", quarters);
    // printf ("dimes:     %i\n", dimes);
    // printf ("nickels:   %i\n", nickels);
    // printf ("pennies:   %i\n", pennies);
    // printf ("total:   %i\n", quarters + dimes + nickels + pennies);
    printf("%i\n", quarters + dimes + nickels + pennies);
}
