//This code performs a substitution cipher using a alphabetic key in a ramdom order
#include "cs50.h"
#include "cs50.c"
#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include <stdlib.h>
int validateKey(string);
string getUserInput(void);
void cipher(string, string);
int main(int argc, string argv[])
{
    //Confirm the command line arguments
    if (argc != 2)
    {
        printf("Usage: ./Substitution key \n");
        return 1;
    }
    //Check if key has 26 characters
    else if (validateKeyargv[1]) == 1)
    {
        printf("Key must contain 26 characters. \n");
        return 1;
    }
    //Check if key only contains alphabetic characters
    else if (validateKey(argv[1]) == 2)
    {
        printf("Key must only contain alphabetic elements. \n");
        return 1;
    }
    //Check for duplicate values
    else if (validateKey(argv[1]) == 3)
    {
        printf("Key must not contain repeated characters \n");
        return 1;
    }
    //Cipher
    else
    {
        //Get user word to cipher
        string userInput = getUserInput();
        //Execute the cipher
        cipher(userInput, argv[1]);
    }
}
//Function to validate the key
int validateKey(string key)
{
    int result;
    // Get the key length
    int n = strlen(key);
    //Return invalid length
    if (n != 26)
    {
        result = 1;

    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            //Stop if it is not alphabetic
            if (!isalpha(key[i]))
            {
                result = 2;
                break;

            }
            //Check for duplicate values
            else if (isalpha(key[i]))
            {
                for (int j = i + 1; j < n; j++)
                {
                    int caseSensitive = tolower(key[i]);
                    int caseSensitiveComparison = tolower(key[j]);
                    if (caseSensitive == caseSensitiveComparison)
                    {
                        
                        result = 3;
                        break;
                    }  

                }
            }
            //Continue if not
            else
            {
                result = 0;
            }
        }
    }
    
    return result;
}



//Function to get user imput.
string getUserInput(void)
{
    string input = get_string("plaintext: ");
    return input;
}

void cipher(string userInput, string key)
{
    //Get user input length
    int length = strlen(userInput);
    printf("ciphertext: ");
   
     
    for (int i = 0; i < length ; i++)
    {
        //Print non alphabetic characters
        if (!isalpha(userInput[i]))
        {
            printf("%c", userInput[i]);
            continue;
        }

        else
        {
            //Case insensitive working with lower case characters
            if (islower(userInput[i]))
            {
                //Convert everything to low case
                int lowCaseInput = tolower(userInput[i]);
                int lowCaseKey = tolower(userInput[i]);
                //Get the location of the alphabetic letter
                int locationLowCase = (lowCaseInput - 97) % 26;
                //Convert key character to low case
                int cipheredLowCase = tolower(key[locationLowCase]);
                //Print key character low case
                printf("%c", cipheredLowCase);
            }
            
            else
            {
                //Convert everything to upper case
                int upperCaseInput = toupper(userInput[i]);
                int upperCaseKey = toupper(userInput[i]);
                //Get the location of the alphabetic letter
                int locationUpperCase = (upperCaseInput - 65) % 26;
                //Convert key character to upper case
                int cipheredUpperCase = toupper(key[locationUpperCase]);
                //Print key character upper case
                printf("%c", cipheredUpperCase);

            }

        }

    }

    printf("\n");
    
}





