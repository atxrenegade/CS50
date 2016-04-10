// Harleigh Abel Jan 14 2016
// CS50 pset2 
// initials.c
// Program prompts user for name and then prints 
// initials in caps

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    {
    
     
    int lower, upper;
     // prompts user for name and stores string variable
     
    printf("Hello User, what is your name? ");
    string name = GetString();
    
  
    
    // checks name for capitalization and converts lower case to upper
    // prints out user initials capitalized
    
    lower = (int) name;
    upper = toupper(lower);
    printf("\n%d",(char)upper);
    //printf("%c%c\n", name [0], name [5]);
        
    }
    
    return 0;

}