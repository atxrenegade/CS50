#include <cs50.h>
#include <stdio.h>

#define d 3
#define DIM_MAX 9

void play_piece(int board[][DIM_MAX], int *pROW, int *pCOL, int *tile);
void find_blank(int board[][DIM_MAX], int *bROW, int *bCOL);
int legal_move(int *pROW, int *pCOL, int *bROW, int *bCOL, int board[][DIM_MAX]);
void move_tile(int *pROW, int *pCOL, int *bROW, int *bCOL, int board[][DIM_MAX]);

int main (void) //the main function represents the move() function that contains all content of main()

//bool move(board[][DIM_MAX, int tile)
{
    int pROW = 0;
    int pCOL = 0;
    int bROW = 0;
    int bCOL = 0;
    
    int board[DIM_MAX][DIM_MAX];// to be deleted
    int tile = 6; //to be deleted
    
    play_piece(board, &pROW, &pCOL, &tile);
    find_blank(board, &bROW, &bCOL);
    int legal = legal_move(&pROW, &pCOL, &bROW, &bCOL, board);
    
    if (legal == true)
    {
        move_tile(&pROW, &pCOL, &bROW, &bCOL, board);
    }
    else
    {
        return false;
    }
}
/******************************************************/
// play_piece() - get input from user about which tile to play

void play_piece(int board[][DIM_MAX], int *pROW, int *pCOL, int *tile)
{
    for (int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            if (board[i][j] == *tile)
            {
                *pROW = i;
                *pCOL = j;
            }
        }
    }
}
/****************************************************/
// find_blank() - determine blank tile's position in the array

void find_blank(int board[][DIM_MAX], int *bROW, int *bCOL)
{
    for (int i = 0; i < d; i++) 
    {
        for (int j = 0; j < d; j++) 
        {
            if (board[i][j] == (char) 95)
            {
                *bROW = i;
                *bCOL = j;
            }
        }  
    }
}        

/***************************************************/
//TODO if play_piece is not a legal tile to move return false
// else return true
int legal_move(int *pROW, int *pCOL, int *bROW, int *bCOL, int board[][DIM_MAX])
{
    if(*pROW == *bROW && *pCOL == *bCOL - 1)
    {
        return true;
    }
    if(*pROW == *bROW && *pCOL == *bCOL + 1)
    {
        return true;
    }
    if(*pROW == *bROW - 1 && *pCOL == *bCOL)
    {
        return true;
    }
    if(*pROW == *bROW + 1 && *pCOL == *bCOL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/***************************************************/
// move_tile() - swap positions of blank tile and play_piece
void move_tile(int *pROW, int *pCOL, int *bROW, int *bCOL, int board[][DIM_MAX])
{
    int temp[1][1];
    temp[0][0] = board[*pROW][*pCOL];
    board[*pROW][*pCOL] = board[*bROW][*bCOL];
    board[*bROW][*bCOL] = temp[0][0];
}
    