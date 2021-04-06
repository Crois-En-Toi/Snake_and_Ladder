#include "board.h"
#include "snake_and_ladder.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//Tiles Structure
struct tiles{
    int player1;
    int player2;
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

Board *new_board(int snakes_array[2][SNAKE_NUM], int ladder_array[2][LADDER_NUM])
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
                    break;
                }
                else
                {
                    new->game_board[i][j].snake_start = 0;
                    new->game_board[i][j].snake_end = 0;
                }

            }

            //tile is laddeR?
             for(int k=0; k<LADDER_NUM; k++)
            {
                if(new->game_board[i][j].coordinate == ladder_array[0][k])
                {
                    new->game_board[i][j].ladder_start = ladder_array[0][k];
                    new->game_board[i][j].ladder_end = ladder_array[1][k];
                    break;
                }
                else 
                {
                    new->game_board[i][j].ladder_start = 0;
                    new->game_board[i][j].ladder_end = 0;
                }

            }

            //all tiles players are null
            new->game_board[i][j].player1= 0;
            new->game_board[i][j].player2= 0;
        }
    }

    return new;
}


//access various members of board through abstraction


int is_snake(Board * board, int coord)
{
    //code for i,j
    int i=0,j=0;
    j=coord%10;
    i=(int)coord/10;
    //code for i,j

    if(coord == 0)
    {
        return 0;
    }

    if(board->game_board[i][j].snake_start == coord)
    {
        return 1;
    }

    return 0;
}

int is_ladder(Board * board, int coord)
{
    //code for i,j
    int i=0,j=0;
    j=coord%10;
    i=(int)coord/10;
    //code for i,j

    if(coord == 0)
    {
        return 0;
    }

    if(board->game_board[i][j].ladder_start == coord)
    {
        return 1;
    }

    return 0;
}

void set_player_coordinate(Board* board, int coord_prev,int coord_next, int player_num)
{
    if(coord_next>99)
    {
        coord_next==coord_prev;
    }

    //code for i,j
    int i=0,j=0;
    j=coord_prev%10;
    i=(int)coord_prev/10;
    //code for i,j
    
    if(player_num == 1)
    {
        board->game_board[i][j].player1=0;
    }
    else
    {
        board->game_board[i][j].player2=0;
    }


    //code for i,j
    i=0,j=0;
    j=coord_next%10;
    i=(int)coord_next/10;
    //code for i,j

    if(player_num == 1)
    {
        board->game_board[i][j].player1=1;
    }
    else
    {
        board->game_board[i][j].player2=1;
    }    
}

int get_snake_tail(Board *board, int coordinate)
{
    //code for i,j
    int i=0,j=0;
    j=coordinate%10;
    i=(int)coordinate/10;
    
    return board->game_board[i][j].snake_end;
}

int get_ladder_end(Board *board, int coordinate)
{
    //code for i,j
    int i=0,j=0;
    j=coordinate%10;
    i=(int)coordinate/10;
    
    return board->game_board[i][j].ladder_end;
}


