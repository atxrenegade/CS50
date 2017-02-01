//*******************************
// Harleigh Abel
// August 22, 2016
/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int board[][DIM_MAX], int tile);
void play_piece(int board[][DIM_MAX], int *pROW, int *pCOL, int *tile);
void find_blank(int board[][DIM_MAX], int *bROW, int *bCOL);
int legal_move(int *pROW, int *pCOL, int *bROW, int *bCOL);
void move_tile(int *pROW, int *pCOL, int *bROW, int *bCOL, int board[][DIM_MAX]);
int won(int board[][DIM_MAX], int d);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won(board, d))
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(board, tile)) 
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}
/*******************************************************/
/**********FUNCTION DEFINITIONS*************************/
/*******************************************************/
/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}
/*******************************************************/
/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}
/*******************************************************/
/**
 * Initializes the game's board with tiles numbered 1 through (d * d) - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{   
    int i;
    int j;
    int tile_value = (d * d);
    
    if (tile_value % 2 != 0)
    // initiate board for even number of playing pieces + 1 blank tile = total number od pieces is odd
    {   
        for (i = 0; i < d; i++)
        {
            for (j = 0; j < d; j++)
            {
                tile_value --;
                board[i][j] = tile_value;
            }
        }
    } 
    // initiate board for odd number of playing pieces + 1 blank tile = total number od pieces is even
    else
    {
        for (i = 0; i < d; i++)
        {
            for (j = 0; j < d; j++)
            {
                tile_value --;
                board[i][j] = tile_value;
                
                // reverses position of tile 1 and tile 2
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
} 
/*******************************************************/
/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {   
            if (board[i][j] == 0 && d < 9)
            {   
                // prints and visually aligns blank tile for single digit boards
                printf(" %c ", (char) 95);//*********
            }
            else if (board[i][j] == 0)
            {
                printf("%c", (char) 95);//***********
            }
            else if (board[i][j] < 10)
            {
                // prints whitespace to visually align single digit numbers
                printf(" ");
                // prints correct number of tiles
                printf("%d ", board[i][j]);
            }
            else
            {
                // prints correct number of tiles
                printf("%d ", board[i][j]);
            }
        }
        // prints new line after each row
        printf("\n");
    }   
}
/*******************************************************/
/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int board[][DIM_MAX], int tile)
{
    // inititates variable for the row and column number of the blank tile
    // and the tile being played
    int pROW = 0;
    int pCOL = 0;
    int bROW = 0;
    int bCOL = 0;
   
    // gets tile number being played for user and stores its position
    play_piece(board, &pROW, &pCOL, &tile);
    // finds the location of the blank tile
    find_blank(board, &bROW, &bCOL);
    // check whether requested move is legal
    int legal = legal_move(&pROW, &pCOL, &bROW, &bCOL);
    // if move is legal blank tile and tile being played swap positions
    if (legal == true)
    {
        move_tile(&pROW, &pCOL, &bROW, &bCOL, board);
        return true;
    }
    // returns false for illegal moves
    else
    {
        return false;
    }
}
/*******************************************************/
// play_piece() - get input from user about which tile to play
// and stores it's position

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
/*******************************************************/
// find_blank() - locates blank tile and stores 
// it's position on the board
void find_blank(int board[][DIM_MAX], int *bROW, int *bCOL)
{
    for (int i = 0; i < d; i++) 
    {
        for (int j = 0; j < d; j++) 
        {
            if (board[i][j] == 0)
            {
                *bROW = i;
                *bCOL = j; 
            }
        }  
    }
}        

/*******************************************************/
// if play_piece is not a legal tile to move return false
// else return true

int legal_move(int *pROW, int *pCOL, int *bROW, int *bCOL)
{
    if(*pROW == *bROW && *pCOL == *bCOL - 1)
    {
        return true;
    }
    else if (*pROW == *bROW && *pCOL == *bCOL + 1)
    {
        return true;
    }
    else if (*pROW == *bROW - 1 && *pCOL == *bCOL)
    {
        return true;
    }
    else if (*pROW == *bROW + 1 && *pCOL == *bCOL)
    {
        return true;
    }
    else
    {
        return false;
    }
    return true;
}

/*******************************************************/
// move_tile() - swap positions of blank tile and play_piece
void move_tile(int *pROW, int *pCOL, int *bROW, int *bCOL, int board[][DIM_MAX])
{
    int temp[2][2];
    temp[1][1] = board[*pROW][*pCOL];
    board[*pROW][*pCOL] = board[*bROW][*bCOL];
    board[*bROW][*bCOL] = temp[1][1];
}

/*******************************************************/   
/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
int won(int board[][DIM_MAX], int d) 
{
    int x = 0;
    while (x < (d * d))
    {
        if (board[d -1][d - 1] == 0)
        {
            x = 1;
        }
        else
        {
            return false;
        }
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
                }
                else
                {
                    return false; 
                }
            }
        }
    }    
    return false;
}
  