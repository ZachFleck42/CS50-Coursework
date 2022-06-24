#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins with a score of %i (versus Player 2's score of %i)\n", score1, score2);
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins with a score of %i (versus Player 1's score of %i)\n", score2, score1);
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Compute and return score for string
    int n = strlen(word);
    int score = 0;

    for (int i = 0; i < n; i++)
    {
        // if (word[i] > 64 && word[i] < 91)
        if (isupper(word[i]) != 0)
        {
            int x = word[i] - 65;
            score = score + POINTS[x];
        }
        //else if (word[i] > 96 && word[i] < 123)
        else if (islower(word[i]) != 0)
        {
            int x = word[i] - 97;
            score = score + POINTS[x];
        }
    }
    return score;
}