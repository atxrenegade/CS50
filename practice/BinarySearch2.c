#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define true 1
#define false 0

bool search(int value, int values[], int n);

int main(void)
{
    int n = 7;
    int value = 34;
    int values[] = {3, 12, 19, 24, 34, 49};
    
    search(value, values, n);
    
}

bool search(int value, int values[], int n)
{
    if (n == 1)
    {
        printf("false\n");
        return false;
    }
    else
    {
        printf("true\n");
        return true;
    }
}