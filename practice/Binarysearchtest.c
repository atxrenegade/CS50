
#include <cs50.h>
#include <math.h>

bool search(int value, int values[], int n);
int binary_search(int value, int values[], int n, int *found);
int findMidpoint( int *max, int *min, int *mid);

int main(void)
{
    int n = 7;
    int value = 34;
    int values[] = {3, 12, 19, 24, 34, 49};

    search(value, values, n);
    
    return 0;
    
}
/******************************************************************************/
bool search(int value, int values[], int n)
{   
    if (n < 1)
    {
        return false;
    }
    else
    {   
        int found = -1;
        found = binary_search(value, values, n, &found);
        if (found == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
/*********************************************************************************/
int binary_search(int value, int values[], int n, int *found)
{
    int min = 0;
    int max = n - 1;
    int mid = 0;
    mid = findMidpoint(&max, &min, &mid);
    
    while(*found == -1)
    {
        if(value == values[mid]) 
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
/******************************************************/

int findMidpoint(int *max, int *min, int *mid)
{
  *mid = round((float)(*max - *min))/2;
  int midpoint = *max - *mid;
  return midpoint;
}

