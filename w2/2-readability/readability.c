#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
// Setting up all needed libraries

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);
// Pre-declaring the functions to be used

int main(void)
{
    string text = get_string("Text: ");
    float letters = count_letters(text);
    printf("%f letters\n", letters);
    float words = count_words(text);
    printf("%f words\n", words);
    float sentences = count_sentences(text);
    printf("%f sentences\n", sentences);

    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;

    // printf("%f L\n", L);
    // printf("%f S\n", S);
    // DEBUG

    float index = 0.0588 * L - 0.296 * S - 15.8;
    // Readability index calculation

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        if (index < 1)
        {
            printf("Before Grade 1\n");
        }
        else
        {
            int grade = round(index);
            printf("Grade %i\n", grade);
        }
    }
}

float count_letters(string text)
{
    // counting all letters in the text
    int i = 0;
    int letters = 0;
    int length = strlen(text);
    string t = text;
    for (i = 0; i < length; i++)
    {
        // converting all lowercase letters to uppercase letters
        t[i] = toupper(t[i]);
    }
    for (i = 0; i < length; i++)
    {
        if (t[i] >= 65 && t[i] <= 90)
        {
            // summing up the number of found letters, after making them uppercase, with their ASCII
            // values
            letters += 1;
        }
    }
    return letters;
}

float count_words(string text)
{
    // counting all words in the text
    int i = 0;
    int words = 1;
    int length = strlen(text);
    string t = text;
    for (i = 0; i < length; i++)
    {
        if ((t[0] != 32 && t[i] == 32 && t[i - 1] != 32) || (t[i] == 0))
        {
            // count words by number of whitespaces dividing the words, excluding whitespaces in the
            // beggining, and consecutive ones

            words += 1;
        }
    }
    return words;
}

float count_sentences(string text)
{
    // counting the sentences in the text
    int i = 0;
    int sentences = 0;
    int length = strlen(text);
    string t = text;
    for (i = 0; i < length; i++)
    {
        if (t[i] == 33 || t[i] == 46 || t[i] == 63)
        {
            // consider as sentence the existence of dots, exclamations and question marks
            sentences += 1;
        }
    }
    return sentences;
}
