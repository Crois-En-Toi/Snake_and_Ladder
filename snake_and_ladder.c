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
    int start;
    int end;
};

struct tiles{
    char* player;
    struct snake* Snake;
    struct ladder* Ladder;
    int coordinate;
};

struct board{
    struct tiles game_board[10][10];
    int snakes[SNAKE_NUM];
    int ladder[LADDER_NUM];
};

