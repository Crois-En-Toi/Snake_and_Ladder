#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define SNAKE_NUM 10
#define LADDER_NUM 7

//Tiles Structure
struct tiles{
    char* player1;
    char* player2;
    int snake_start;
    int snake_end;
    int ladder_start;
    int ladder_end;
    int coordinate;
};

typedef struct tiles Tiles;
//end of tiles

struct board{
    Tiles game_board[10][10];
};

Board* new_board(int **snakes_array, int **ladder_array)
{
    Board* new = malloc(sizeof(*new));
    assert(new!=NULL);
    
    //initializing all tiles with players as NULL snakes and NULL ladder NULL
    //coordinates assigned

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            new->game_board[i][j].coordinate = i*10+j;
            //tile_is_a_sanke ?
            for(int k=0; k<SNAKE_NUM; k++)
            {
                if(new->game_board[i][j].coordinate == snakes_array[0][k])
                {
                    new->game_board[i][j].snake_start = snakes_array[0][k];
                    new->game_board[i][j].snake_end = snakes_array[1][k];
                }
            }

            //tile is laddeR?
             for(int k=0; k<LADDER_NUM; k++)
            {
                if(new->game_board[i][j].coordinate == ladder_array[0][k])
                {
                    new->game_board[i][j].ladder_start = ladder_array[0][k];
                    new->game_board[i][j].ladder_end = ladder_array[1][k];
                }
            }

            //all tiles players are null
            new->game_board[i][j].player1=NULL;
            new->game_board[i][j].player2=NULL;
        }
    }

    return new;
}