#ifndef BOARD_H
#define BOARD_H
#define SNAKE_NUM 10
#define LADDER_NUM 7

typedef struct board Board;

Board* new_board(int snakes_array[2][SNAKE_NUM], int ladder_array[2][LADDER_NUM]);



#endif
