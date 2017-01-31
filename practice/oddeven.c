#include <cs50.h>
#include <stdio.h>

int value;

int main (void) 
{
    
    value = GetInt();
    
    if (value % 2 == 0)
    {
        printf("It's even!\n");
    }
    else
    {
         printf("It's odd!\n");
    }
}