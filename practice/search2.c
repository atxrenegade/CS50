#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// prototype
bool search(int value, int values[], int n); 
// prototype
int calcMidpoint(int n);


int main(void)
{
    int target_val = GetInt();
    int n = 13;
    int values[] = {3, 5, 9, 23, 24, 38, 53, 112, 187, 243, 345, 463, 1028};
    
    /***************to shut up warnings*/
    printf("%i,%i,%i\n", target_val, n, values[0]);
    
    // calling function
     bool search(int value, int values[], int n);
     
     
}

// function definition
int calcMidpoint(int n)
{
    int midVal = (float) round(n / 2);
    return midVal;
}

bool search(int value, int values[], int n)
{
    int lowVal = 0;
    int highVal = n - 1;

    // can I turn my do while loop into a for loop?
    // why the hell when I am passing variables to a function as parameter does it say they are unused variables?
    // bool is returning false everytime why?
    // can i use the debugger to walk through the bool search and calc midpoint function?
    
    do 
    {   
        int midPoint = calcMidpoint(n);
        if (value == values[midPoint])
        {
            return true;
        }
        else if (value < values[midPoint])
        {
            highVal = midPoint;
            n = highVal;
        }
        else 
        {
            lowVal = midPoint;
            n = highVal - lowVal;
        }
       n = midPoint;
    }    
    while (highVal > lowVal);
    
    if (highVal < lowVal)
    {
        return false;
    }
    
    return false;
}