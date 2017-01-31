 #include <cs50.h>
 #include <stdio.h>
 
  void sort(int values [], int n);
  
 int main(void)
 {
     
  int values[] = {2, 74, 8, 231, 4, 756, 84, 35, 7};
  int n = 9;
  sort(values, n);
  
  for (int i = 0; i < n; i++)
  {
  printf("%i\n", values[i]);   
      
  }
 }
 /* Sorts array of n values.
 */
void sort(int values[], int n)
// TODO: implement an O(n^2) sorting algorithm
{
    for (int i = 0; i < n ; i++)
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