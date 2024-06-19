#include <cs50.h>
#include <stdio.h>
#include <string.h>

int collatz(int n);

int main(void)
{
    int n = get_int("n: ");
    printf("collatz steps: %i\n", collatz(n));
    return 0;
}

int collatz(int n)
{
    // base case
    if (n == 1)
        return 0;

    // even numbers
    else if ((n % 2) == 0)
        return 1 + collatz(n / 2);

    // odd numbers
    else
        return 1 + collatz(3 * n + 1);
}
