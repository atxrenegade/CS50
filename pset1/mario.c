// Harleigh Abel
// CS50 pset1 Oct 2015 
// mario.c
// This program builds a primitive Super Mario style pyramid
// from a height based on user input
 
#include <stdio.h>
#include <cs50.h>
 
int main(void)
{
    /*Creates an int to store pyramid height specified by user*/
    int height; 
 
    // Prompts user for int value < 24 and > 0 and loops until condition is met
    do
    {
        printf("\nPlease give me a positive integer less than 24: ");
        height = GetInt ();
    }
     while
        (height < 0 || height > 23.);   
         
    // Repeats pyramid print instructions until users height is reached    
    for (int row = 0; row < height; row++)  
    {  
      
        // Prints appropriate number of space per row
        for (int spaces = height - row; spaces > 1; spaces--)
        {
            printf(" ");
        }
             
         // Prints appropriate number of hashes per row   
        for (int hashes = 0; hashes < row + 2; hashes++)
        {
            printf("#");
        }
         
        // Creates new line after each row
        printf("\n");
         
    }
         
    return 0;   
}
 
    