#include <cs50.h>
#include <math.h>
#include <stdio.h>

int findMidpoint(int *max, int *min);

int main(void)
{
 int n = 7;
 int values[] = {4, 23, 81, 92, 102, 119, 145};
 int max = n - 1;
 int min = 0;
 int midpoint = findMidpoint(&max, &min);
 printf("the midpoint position is %i, and the midpoint value is %i\n", midpoint, values[midpoint]);
}

/********************************/
int findMidpoint(int *max, int *min)
{   
    int mid = round((float)(*max - *min)/2);
    return mid;
}