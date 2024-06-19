// This headers provide access to the string and get_string functions
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declares a string var and gets its value as input,
    // with the specified message to the user
    string name = get_string("What's your name? ");

    // Prints the desired text putting the variable's text inside the string "name" withing it
    printf("hello, %s\n", name);
}
