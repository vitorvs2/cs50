#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Letters array with loop to populate the array
int LETTERS[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
                 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else
    {
        if (score1 == score2)
        {
            printf("Tie!");
        }
        else
        {
            printf("Player 2 wins!");
        }
    }
    printf("\n");
}

int compute_score(string word)
{
    int i = 0, p = 0, length = strlen(word);

    for (i = 0; i < length; i++)
    {
        word[i] = toupper(word[i]);
    }

    for (i = 0; i < length; i++)
    {
        if (word[i] >= 65 && word[i] <= 90)
        {
            for (int j = 0; j <= 25; j++)
            {
                if (word[i] == LETTERS[j])
                {
                    p = p + POINTS[j];
                }
            }
        }
    }
    // TODO: Compute and return score for string
    return p;
}
