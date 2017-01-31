#include <cs50.h>
#include <stdio.h>

void create_board(int board[][9], int d);
void print_board(int board[][9], int d);
int won(int board[][9], int d);


//void check_board(int board[][9]);

int main(void)
{

    int board[9][9];
    int d = 4;
    create_board(board, d);
    print_board(board, d);
    //check_board(board);
        
    int winner = won(board, d); 
    printf("%d", winner);
    
    return 0;
}

/***********************************************/
void create_board(int board[][9], int d)
{
    int x = 0;  
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            board[i][j] = x;
            x++;
        }
    }

}

/*********************************************/

void print_board(int board[][9], int d)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            printf("%d ", board[i][j]);
        }
        
        printf("\n");
    }
    
}

/**********************************************/
//void check_board(int board[][9])
//{
    
    
    
    
//}






/********************************************/
int won(int board[][9], int d) 
{
    if (board[0][0] == 0)// change to board[d][d] for actual game
    // if blank piece is in correct position continue
    {
        int x = 0; //change to x = 1 for actual game
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (x == (d * d - 1))
                {
                    return true;
                }
                else if (board[i][j] == x)
                {
                    x++;
                    printf("Check %d\n", x); //*****test
                }
                else
                {
                  return false; //******test
                  printf("%d doesnt match", x); //********test
                  
                }
            }
        }
    }    
    else
    {
        return false;
    }
    return false;
}
    
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    /*int x = d * d - 1;
    for (int i = 0; i < d; i--)
        {
            for ( int j = 0; j < d; j++)
            {
                int x = d * d - 1;
                if (board[i][j] == x)
                {
                    x--;
                    if (x == 8)
                    {   
                        return 1;
                        printf("%d\n", x);
                    }
                }
            }
        }
    
    return 0; */
    
