// Harleigh Abel
// CS50 pset1 Jan 2016
// water.c
// Program calculates number of 16 ounce btls of water
// would have been used per minute of shower taken

#include <cs50.h>
#include <stdio.h>

int main(void)
{
   
    
   // Output question to screen to determine 
   // users length of shower in minutes 
    printf ("How long was your shower in minutes?\n"
        "Please enter a positive integer\n");
        
     // initialize variable for length of shower in minutes
     // while storing integer input from user
    int showlen = GetInt();
    
     // initialize variable for number of 16 oz btls of water used
    // of water used and calculate the answer using user input
    int btlwat = showlen * 192 / 16;
    
    // output btls of water used to screen
    printf ("%i\n", btlwat);
    
    return 0;
    
}
    