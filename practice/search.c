#include <cs50.h>
#include <stdio.h>
#include <math.h>

// prototype
bool search(int value, int values[], int n); 
// prototype
int calcMidpoint(int n);


int main(void)
{
    int target_val = GetInt();
    int n = 13;
    int values[] = {3, 5, 9, 23, 24, 38, 53, 112, 187, 243, 345, 463, 1028};
    
    int lowVal = values[0];
    int highVal = values[n - 1];
   
    // calling function
    bool search(int value, int values[], int n);
    


    //**************test part to return values to prevent unused variable warning
  
    printf("%i\n%i\n", target_val, n);
    printf("low val = %i, high val = %i\n", lowVal, highVal);
    
    for (int i = 0; i < 13; i++)
    {
        printf("%i ", values[i]);
    }
    printf("\n");
    printf("midPoint = %i\n", midVal);
    printf("%i\n", values[midVal]);
    
    if ((int)search == 1)
    {
        printf("true\n");
    }
    //else
    //{ 
    //   printf("false\n");
    //}
    //*******************ends here
    return 0;
}

// function definition
int calcMidpoint(int n)
{
    int midVal = (float) round(n / 2);
    return midVal;
}

bool search(int value, int values[], int n)
{
    int lowVal = values[0];
    int highVal = values[n - 1];
    int midPoint = calcMidpoint(n);
    
    do 
    {   
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
       // ???????calculate new midpoint
       // how many elements are left in the array
       // count the number of elements and divide by 2 
       // the nu
       // midPoint = calcMidpoint
       n = midPoint;
    }    
    while (highVal > lowVal);
    
    if (highVal < lowVal)
    {
        return false;
    }
    // ************test
    
    return false;
    
}