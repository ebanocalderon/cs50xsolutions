// This program builds graphics stairs & tower as in Mario Bros game
#include "cs50.h"
#include "cs50.c"
#include <stdio.h>
//Functions declaration
int  stairsHeightInput(void);
char stairsTypeInput(void);
void upStairs(int);
void downStairs(int);
void tower(int);


int main(void)
{

//Get user input
    char type = stairsTypeInput();
    int height =  stairsHeightInput();

//Check what will be built
    if (type == 'U' || type == 'u')
    {
        upStairs(height);
    }
    else if (type == 'T' || type == 't')
    {
        tower(height);
    }
    else
    {
        downStairs(height);
    }

}

// Functions

//Get height input
int stairsHeightInput(void)
{
    int input;
    do
    {
        input = get_int("Building Height(Max Height 8):");
    }
    //Accept only values between 1 & 8
    while (input < 1 | input > 8);
    return input;
}

char stairsTypeInput(void)
{
    char input;
    do
    {
        input = get_char("Insert building type, U for Upstairs, D for Downstairs, T for Tower: ");
    }
    //Accept only requested chars
    while (input != 'D' && input != 'd' && input != 'U' && input != 'u' && input != 'T' && input != 't');
    return input;
}


void upStairs(int height)
{
    //Main loop for height of stairs
    for (int i = 0; i < height; i++)
    {
        // Add space for steps up
        for (int k = 1; k < height - i; k++)
        {
            printf(" ");
        }
        //Upstairs blocks
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        //New line of building
        printf("\n");
    }
}
void downStairs(int height)
{
    //Main loop for height of stairs
    for (int i = 0; i < height; i++)

    {
        //Downstairs blocks
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        //New line of building
        printf("\n");

    }

}

void tower(int height)
{
//Main loop for height of tower
    for (int i = 0; i < height; i++)
    {
        // Add space for steps up
        for (int k = 1; k < height - i; k++)
        {
            printf(" ");
        }
        //Downstairs blocks
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        //Gap between stairs
        printf("  ");

        //Downstairs blocks
        for (int g = 0; g < i + 1; g++)
        {
            printf("#");
        }
        //New line of building
        printf("\n");
    }

}


