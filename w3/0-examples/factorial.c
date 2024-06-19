// include needed libs
#include <cs50.h>
#include <stdio.h>

// factorial function prototype
int factorial(int n);

// main function
int main(void)
{
    // Get positive value for n
    int n;
    do
    {
        n = get_int("n: ");
    }
    while (n < 0);

    // Print the factorial of n
    printf("%i\n", factorial(n));
}

// factorial recursive function
int factorial(int n)
{
    // base case
    if (n == 1)
    {
        return 1;
    }

    // factorial function recursive call
    return n * factorial(n - 1);
}
