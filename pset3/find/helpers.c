//******************************************/
// Harleigh Abel
// August 3, 2016

/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <string.h>
#include <math.h>


#include "helpers.h"

int binary_search(int value, int values[], int n, int found);
int findMidpoint(int *max, int *min, int *mid);
void sort(int values[], int n);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n < 1)
    {
        return false;
    }
    else
    {   
        int found = -1;
        int result = binary_search(value, values, n, found);
        
        if (result == 1)
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }
}

//******************************************/
// binary_search() - uses binary search to find a user 
// input target value
int binary_search(int value, int values[], int n, int found)
{
    int min = 0;
    int max = n - 1;
    int mid = 0;
    mid = findMidpoint(&max, &min, &mid);
    
    while (found == -1)
    {
        if (value == values[mid])
        {
            found = 1;
            return (found);
        }
        else if (max < min)
        {
            found = 0;
            return (found);
        }
        else
        {
            if (values[mid] < value)
            {
                min = mid +1;
                found = -1;
                mid = findMidpoint(&max, &min, &mid);
            }
            else if (values[mid] > value)
            {
                max = mid - 1;
                found = -1;
                mid = findMidpoint(&max, &min, &mid);
            }
            else
            {
                found = 1;
                return (found);
            }
        }
    }
    return (found);
}
//******************************************/
// findMidpoint() - calculates the midpoint of array being 
// search by binary search and returns the value
int findMidpoint(int *max, int *min, int *mid)
{
    *mid = round((float)(*max - *min))/2;
    int midpoint = *max - *mid;
    return midpoint;
}
//******************************************/
// Sorts an array of n values using insertion sort 
void sort(int values[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int element = values[i];
        int j = i;
        while ((j > 0) && (values[j - 1] > element))
        {
            values[j] = values[j - 1];
            j = j - 1;
        }
        values[j] = element;
    }
}