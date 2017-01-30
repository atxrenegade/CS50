/**
 * helpers.h
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n);

/**
 * Sorts array of n values using insertion sort.
 */
void sort(int values[], int n);

/**
 * Searches array using binary search and return result to Search()
 */
 int binary_search(int value, int values[], int n, int found);
 
 /**
  * Calculates midpoint in array, returns midpoint value to binary_search 
 */
 int findMidpoint(int *max, int *min, int *mid);