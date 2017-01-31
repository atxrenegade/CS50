#include <stdio.h>
#include <cs50.h>
#include <math.h>

int findMidpoint( int *max, int *min, int *midpoint);
int binary_search(int value, int values[], int n, int *found);

int main (void)
{
    int n = 7;
    int value = GetInt();
    int values[] = {3, 12, 19, 24, 34, 49, 57};  
    int found = -1;
    
    
    int result = binary_search(value, values, n, &found);
    printf("%d\n", result);
    //return 0;
    
}    
/******************************************************************************/    
int binary_search(int value, int values[], int n, int *found)
{
    int min = 0;
    int max = n - 1;
    int mid = 0;
    mid = findMidpoint(&max, &min, &mid);
    
    while(*found == -1)
    {
        if(value == values[mid]) //this entire if statement needs to be a while loop
        {
            *found = 1;
            return (*found);
        }
        else if (max < min)
        {
            *found = 0;
            return (*found);
        }
        else
        {   
            
            if (values[mid] < value)
            {
                min = mid + 1;
                *found = -1;
                mid = findMidpoint(&max, &min, &mid);
             
            }
            else if (values[mid] > value)
            {
                max = mid - 1;
                *found = -1;
                mid = findMidpoint(&max, &min, &mid);
            }
            else
            {
                *found = 1;
                return *found;
            }
        } 
    }    
    
    return *found;
}

//new midpoint to executing, new min and max are okay
// proram finds the value if it is present but gets caught 
// in an infinite loop if value is not present in array
// midpoint is buggy after first execution?? I THINK IT'S FIXED!!!
/******************************************************/

int findMidpoint(int *max, int *min, int *mid)
{
  *mid = round((float)(*max - *min))/2;
  int midpoint = *max - *mid;
  return midpoint;
}
