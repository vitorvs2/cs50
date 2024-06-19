#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// importing all required libraries

bool only_digits(string s);
// function that checks if there are only digits as arguments

char rotate(char c, int n);
// function that rotates the character c by n times

// main function where argc is the number of arguments and argv the arguments to be received
int main(int argc, string argv[1])
{
    if (argc == 1 || argc > 2)
    {
        // checks if there is only one argument to run the program, if more or less it returns error
        // 1
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (!only_digits(argv[1]))
    {
        // checks if there are only digits in the provided argument, if not it returns error 1
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    // convert the key provided in the arguments from text to integer
    string plaintext = get_string("plaintext: ");

    // gets the string to be encripted

    string ciphertext = plaintext;
    // sets the value of ciphertext to be the same as the plaintext (memory issues)

    int i = 0, length = strlen(plaintext);
    // gets the length of the whole string to be encripted and starts the counter to walk trough the
    // whole string

    for (i = 0; i < length; i++)
    {
        // walks trouth all the characters in the plaintext

        ciphertext[i] = rotate(plaintext[i], key);
        // rotates the character from the plaintext into the ciphertext

        // printf("cipher char: %c\n", ciphertext[i]);
        // DEBUG
    }

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

bool only_digits(string s)
{
    int i = 0, length = strlen(s);
    for (i = 0; i < length; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    int cha = c;
    // set the char into a int value, allowing manipulation

    if (cha >= 65 && cha <= 90)
    {
        // checks and manipulates the char if is uppercase

        cha = (cha - 65 + n) % 26;
        // rotates the character, also subtracting the real value of the char to make the encription
        // formula to work (need to match alphabet letter position)

        // printf("cha: %i\n",cha);
        // DEBUG

        return cha + 65;
        // gives back the subtracted value
    }

    if (cha >= 97 && cha <= 122)
    {
        // checks and manipulates the char if is lowercase

        cha = (cha - 97 + n) % 26;
        // rotates the character, also subtracting the real value of the char to make the encription
        // formula to work (need to match alphabet letter position)

        // printf("cha: %i\n",cha);
        // DEBUG

        return cha + 97;
        // gives back the subtracted value
    }

    return cha;
}
