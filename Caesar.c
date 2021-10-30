//This code do a Caesar cipher to a plaintext provided by the user
#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include <stdlib.h>
bool checkKey(string);
string getUserInput(void);
void cipher(string, int);
int main(int argc, string argv[])
{
    //Confirm the command line arguments 
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");

    }
    //Check if key is alphanumeric not valid - we need an integer
    else if (checkKey(argv[1]))
    {
        printf("Usage: ./caesar key \n");
    }
    //Cipher
    else
    {
        //Convert the command line argument to int
        int key = atoi(argv[1]);
        //Get user word to cipher
        string userInput = getUserInput();
        //Execute the cipher 
        cipher(userInput, key);
    }
}
//Function to check if the key is alphanumeric
bool checkKey(string key)
{
    bool result;
    // Get the key length
    int n = strlen(key);
    //Check all the character of the key
    for (int i = 0; i < n; i++)
    {
        //Stop if it is an alphanumeric
        if (isalpha(key[i]))
        {
            result = true;
            break;
        }
        //Continue if not
        else
        {
            result = false;
        }
    }

    return result;
    
}

//Function to get user input
string getUserInput(void)
{
    string input = get_string("plaintext: ");
    return input;
}

void cipher(string userInput, int key)
{
    int n = strlen(userInput);
    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(userInput[i]))
        {
            printf("%c", userInput[i]);
            continue;
        }
        // Check for upper case and assign value;
        int difference = isupper(userInput[i]) ? 65 : 97;
        // Calculating the asci value difference
        int pi = userInput[i] - difference;
        // Get the location of the letter to be ciphered
        int ci = (pi + key) % 26;

        // Print the ciphered text
        printf("%c", ci + difference);
    }
    printf("\n");
 
}

