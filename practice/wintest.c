#include <cs50.h>
#include <stdio.h>

#define d 4

int main (void)
{
    int board[9][9]; // LTBD DELETED
    board[d][d] = char // LTBD
    
    winval = 0;
    
    if (board[d][d] != char(95))
    {
        return false;
    }
    
    for (int i = 0; i < d; i++)
    {
        for ( int j = 0; j < d; j++)
        {
            if (board[i][j] !== winval)
            {
                return false;
            }
            else
            {
                return true;
            }
            winval++;
        }
    }
}

/***************** To be tested!!!*********/