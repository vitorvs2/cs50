// Main libs declaration
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// New data structure "person" linking names and numbers
typedef struct
{
    string name;
    string number;
} person;

// Main function
int main(void)
{
    // New "person" array
    person people[3];

    // "person" array data insertion
    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";
    people[1].name = "David";
    people[1].number = "+1-617-495-1000";
    people[2].name = "John";
    people[2].number = "+1-949-468-2750";

    // User input of the string to be searched
    string name = get_string("Name: ");

    // Searching trough the arrays
    for (int i = 0; i < 3; i++)
    {
        // New custom function needed for string comparison
        if (strcmp(people[i].name, name) == 0)
        {
            // Print the found number of found user
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
