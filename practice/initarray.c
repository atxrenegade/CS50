#include <cs50.h>
#include <stdio.h>

#define GRID 4

int main (void) 

{    
    int board [GRID][GRID];
    int d = GRID;
    int j;
    int i;
    
    int tile_value = (d * d);

    if (tile_value % 2 != 0)
    {   // initiate board for even number of playing pieces + 1 blank tile + odd number
        for (i = 0; i < d; i++)
        {
            for (j = 0; j < d; j++)
            {
                tile_value --;
                board[i][j] = tile_value;
            }
       }
    }
    else
    {
        for (i = 0; i < d; i++)
        {
            for (j = 0; j < d; j++)
            {
                tile_value --;
                board[i][j] = tile_value;
                
                if (tile_value == 1)
                {
                    board[i][j] = 2;
                }
                if (tile_value == 2)
                {
                    board[i][j] = 1;
                }
            }
        }
    }
   
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < d; j++)
        {   
            if (board[i][j] == 0 && d < 9)
          
            {
                printf(" %c", (char) 95);
            }
            else if (board[i][j] == 0)
            {
                printf("%c", (char) 95);
            }
            else if (board[i][j] < 10)
            {
                printf(" ");
                printf("%d ", board[i][j]);
            }
            else
            {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }   
}