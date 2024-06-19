// Main libs declaration
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Main function, void this time
int main(void)
{
    // Array of strings to be searched by the algorythim
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    // User input of the string to be searched
    string s = get_string("String: ");

    // Searching trough the strings array for the user value
    for (int i = 0; i < 6; i++)
    {
        // New custom function needed for string comparison
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
}
