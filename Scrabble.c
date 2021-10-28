// This code shows the highest value of 2 strings based on a array of values assigned to all the alphabet letters
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int compute_score(string word);
string scores(int score1, int score2);

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calculate the score
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    string result = scores(score1, score2);

    // Print the winner
    printf("%s", result);

}

//Function to calculate the score of each word
int compute_score(string word)
{
    //Get word length
    int n = strlen(word);
    //Variable to store the array location of every character to calculate the points
    int position = 0;
    // Sum of the score for each word
    int score = 0;
    // Loop to get every character of the word
    for (int  i = 0; i < n; i++)
    {
        //Calculation for lowercase letters
        if (islower(word[i]))
        {
            //Calculate the position
            position = word[i] - 97;
            //Sum the score
            score += POINTS[position];
        }
        //Calculation for upper case letters
        else
        {
            //Calculate the position
            position = word[i] - 67;
            //Sum the score
            score += POINTS[position];
        }

    }

    return score;

}
//Function to print the winner
string scores(int score1, int score2)
{
    string result;
    if (score1 > score2)
    {
        result = "Player 1 wins! \n";
    }
    else if (score2 > score1)
    {
        result = "Player 2 wins! \n";
    }
    else
    {
        result = "Tie! \n";
    }
    return result;
}