#include <cs50.h>
#include <math.h>
#include <stdio.h>

// function prototype to calculate array midpoint 
int calcMidPoint(int valMin, int valMax);
bool search(int value, int values[], int n);

int values[] = {3, 5, 9, 23, 24, 38, 53, 112, 187, 243, 345, 463, 1028};
int n = 13;
int value; = GetInt();
// VALUE is the target value, VALUES are the values in array
// N is the total numnber of values in array

int main(void)
{
    value = GetInt();
    int valMin = values[0];
    // VALMIN is the first position in array
    int valMax = values[n - 1];
    // VALMAX is the last position in array
    int midPoint = 0;
    // MIDPOINT stores the midpoint value in the array

    if (n < 1)
    // if the total number of values is less than 1, exit the program
    {
        // return false
        return 1;
    }
    
    if (valMax < valMin) 
    // checks if VALMAX is less than VALMIN indicating
    // target value is not present
    {
        // return false
        return 1;
    }
    else
    {
        bool search(int value, int values[], int n);
    }
        // loop through array values until VALMAX < VALMIN
        // signalling that the target value is not present in the array 
        
}

//*** FUNCTION calcMidPOint
//Calculate midpoint of array 

int calcMidPoint(int valMin, int valMax)
{
    int midPoint;
    midPoint = valMax - valMin;
    midPoint = (float) round(midPoint / 2);
    return midPoint;
    
}

// FUNCTION SEARCH
// if midpoint is equal to target value search is complete
// program returns true and exits, else returns false
       
bool search(int value, int values[], int n)
{   
    values[midPoint] = calcMidPoint(valMin, valMax);
    //calculates midpoint using calcMidpoint()
    if (values[midPoint] == value)
    {
        return true;
    }
    else
    {
        return false;
    }
}