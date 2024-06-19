// Main libs declaration
#include <cs50.h>
#include <stdio.h>

// Main function, void this time
int main(void)
{
    // Array of numbers to be searched by the algorythim
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    // User input of the integer to be searched
    int n = get_int("Number: ");

    // Searching trough the numbers array for the user value
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
}
