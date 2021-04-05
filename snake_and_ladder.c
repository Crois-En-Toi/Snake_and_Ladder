#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "snake_and_ladder.h"

#define SNAKE_NUM 10
#define LADDER_NUM 7

struct snake{
    int Mouth;
    int Tail;
};

struct ladder {
    int Start;
    int End;
};

struct tiles{
    char* player1;
    char* player2;
    Snake* tile_Snake;
    Tiles* tile_Ladder;
    int coordinate;
};

struct board{
    Tiles game_board[10][10];
    int snakes[SNAKE_NUM];
    int ladder[LADDER_NUM];
};

//logic functions for snake

//This Function creates a new snake
Snake *new_snake(int mouth ,int tail)
{
    Snake *new_snake = malloc(sizeof(*new_snake));
    assert(new_snake!=NULL);
    new_snake->Mouth = mouth;
    new_snake->Tail = tail;
    return new_snake;
}


//logic functions for ladder

//This function creates a new ladder
Ladder *new_ladder(int start,int end)
{
    Ladder *new_ladder = malloc(sizeof(*new_ladder));
    assert(new_ladder!=NULL);
    new_ladder->Start = start;
    new_ladder->End = end;
    return new_ladder;

}

//logic functions for tiles

//This function creates new tiles
Tiles *new_tile(char *plyr_1,char *plyr_2,Snake *snke,Tile *til,int cord)
{
    Tile *new_tile = malloc(sizeof(*new_tile));
    assert(new_tile!=NULL);
    new_tile->player1 = plyr_1;
    new_tile->player2 = plyr_2;
    new_tile->tile_Snake = NULL;
    new_tile->tile_Ladder = NULL;
    return new_tile;
}
 

