// Harleigh Abel 
// CS50 pset1 Oct 2015
// greedy.c
// Program calculates the smallest number of coins to make change

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Creates float for user input change variable
    float change; 
    // Creates variables for # of quarters, dimes, and nickels needed for change
    int quarters, dimes, nickels;
    // Creates variables for change remaining following each calculation  
    // Pennies = change_rem3
    int change_int, change_rem1, change_rem2, change_rem3, num_coins;
    
    
    // Prompts user for change amount and specifies format
    printf("\nHello There!!\n\n");
    printf("How much change do you need?\n");
    printf("(Please enter in the following format XX.XX)\n");
    
    // Retrieves user input and stores change variable as a float
    change = GetFloat (); 
    
    while 
    (change < 0)
    {
        printf("Please use the correct format XX.XX\n");
        change = GetFloat ();
    }
     
    // Converts dollars to pennies; Rounds to nearest penny
    change = round(change * 100.00);
    // Converts change variable from float to int
    change_int = change; 
    // Calculates number of quarters to make change
    quarters = change_int / 25;  
    // Calculates change remaining minus quarters
    change_rem1 = change_int % 25;  
   
    
    // Calculates number of dimes to make change
    {
        dimes = change_rem1 / 10; 
    // Calculates change remaining minus quarters and dimes
        change_rem2 = change_rem1 % 10; 
       
    }
    
    // Calculates number of nickels to make change
        nickels = change_rem2 / 5;  
    // Calculates change remaining minus quarters and dimes = pennies
        change_rem3 = change_rem2 % 5; 
       
    
     // Calculate total number of coins to make change
        num_coins = (quarters + dimes + nickels + change_rem3);
    
     // Returns value to user
        printf("%d\n", num_coins); 
    
        return 0;
    
}