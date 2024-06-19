// importing all required libraries
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function that checks if there are only digits as arguments
bool only_alphabetic(string s);

// function that substitutes the character c due to the 26 digit key
char substituition(char c, string n);

// function that checks char repetition
bool repeated(string s);

// main function where argc is the number of arguments and argv the arguments to be received
int main(int argc, string argv[1])
{

    // key valitation
    // args quantity
    if (argc == 1 || argc > 2)
    {
        printf("Usage: %s KEY\n", argv[0]);
        return 1;
    } else{
        // DEBUG
        printf("args qty: OK\n");
    }
    // length
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    } else{
        // DEBUG
        printf("lenght: OK\n");
    }
    // alphabetic characters only
    if (!only_alphabetic(argv[1]))
    {
        printf("Keys must only contain alphabetic characters.\n");
        return 1;
    } else{
        // DEBUG
        printf("alpha only: OK\n");
    }
    // no repeated characters
    if (repeated(argv[1]))
    {
        printf("Keys must not contain repeated characters.\n");
        return 1;
    } else{
        // DEBUG
        printf("no repeat: OK\n");
    }

    // convert the key provided in the arguments from text to integer
    string key = argv[1];

    // gets the string to be encripted
    string plaintext = get_string("plaintext: ");

    // sets the value of ciphertext to be the same as the plaintext (memory issues)
    string ciphertext = plaintext;

    // gets the length of the whole string to be encripted and starts the counter to walk trough the whole string
    int i = 0, length = strlen(plaintext);

    // walks trouth all the characters in the plaintext
    for (i = 0; i < length; i++)
    {

        // rotates the character from the plaintext into the ciphertext
        ciphertext[i] = substituition(plaintext[i], key);

        // DEBUG
        // printf("cipher char: %c\n", ciphertext[i]);
    }

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

bool only_alphabetic(string s)
{
    int i = 0, length = strlen(s);
    for (i = 0; i < length; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

bool repeated(string s)
{
    int i = 0, sum = 0, length = strlen(s);
    for (i = 0; i < length; i++)
    {
        char c = s[i];
        c = tolower(c);
        sum = sum + c;
    }
    // DEBUG
    // printf("sum: %i\n", sum);
    if (sum == 2015 || sum == 2847)
    {
        return false;
    } else {
        return true;
    }
}

char substituition(char c, string key)
{

    // set the char into a int value, allowing manipulation
    int cha = c;

    // checks and manipulates the char if is uppercase
    if (cha >= 65 && cha <= 90)
    {
        int index = c - 65;

        cha = key[index];

        // DEBUG
        // printf("cha: %i\n",cha);

        // gives back the subtracted value
        return cha;
    }

    // checks and manipulates the char if is lowercase
    if (cha >= 97 && cha <= 122)
    {
        int index = c - 97;
        // rotates the character, also subtracting the real value of the char to make the encription
        // formula to work (need to match alphabet letter position)
        // cha = (cha - 97 + n) % 26;
        cha = key[index];

        // DEBUG
        // printf("cha: %i\n",cha);

        // gives back the subtracted value
        return cha + 97;
    }

    return cha;
}


