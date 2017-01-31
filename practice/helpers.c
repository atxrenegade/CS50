/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <math.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
// function prototype to calculate array midpoint 
int calcMidPoint(int valMin, int valMax);
void sort(int values[], int n);


bool search(int value, int values[], int n)
// VALUE is the target value, VALUES are the values in array
// N is the total numnber of values in array
{
/*
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
    // loop through array values until VALMAX < VALMIN
    // signalling that the target value is not present in the array 
    {   
        values[midPoint] = calcMidPoint(valMin, valMax);
        //calculates midpoint using calcMidpoint()
        if (values[midPoint] == value)
        // if midpoint is equal to target value search is complete
        // program returns true and exits
        {
            // return true
            return 0;
        }
        
        // if midpoint value is less than target value
        // sets new VALMIN to midpoint 
        else if (values[midPoint] < value)
        {
            valMin = values[midPoint];
        }
        // if midpoint value is greater than target value
        // sets new VALMAX to midpoint
        else 
        {
            valMax = values[midPoint];
        }
    return 0;
    }
*/
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int element = values[i];
        int j = i;
        
        while ((j < 0) && (values[j - 1] > element))
        {
            values[j] = values[j - 1];
            j = j - 1 ;
        }
        values[j] = element;
    }
   
}

/** 
 * Calculate midpoint of array
 */ 
int calcMidPoint(int valMin, int valMax)
{
    int midPoint;
    midPoint = valMax - valMin;
    midPoint = (float) round(midPoint / 2);
    return midPoint;
    
}