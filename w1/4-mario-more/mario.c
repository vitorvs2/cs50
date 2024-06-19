#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Set the mario pyramid's heigth: ");
    }
    while (height > 8 || height <= 0);
    // Verifies if height is above zero and not more than eight

    for (int i = 1; i <= height; i++)
    {
        // Starts the main loop that controlls the rows/height of the pyramid

        int n = height - i;
        // Needs to subtract 1 plus the i (if i starts as 0), so there is no extra space when i=0
        while (n > 0)
        {
            printf(" ");
            n--;
        }
        // While loop that creates the space before the hashes, centralizing the pyramid.
        // This reduces based in the height value, because the pyramid widens towards its base
        // (reducing the space)

        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        // Loop that builds the first pyramid

        printf("  ");
        // Space between pyramids

        for (int j = i; j > 0; j--)
        {
            printf("#");
        }
        // Loop that builds the second pyramid

        printf("\n");
        // Goes to the next row/height of the pyramids
    }
}
