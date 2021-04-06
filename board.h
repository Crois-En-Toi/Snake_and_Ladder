#ifndef BOARD_H
#define BOARD_H
#define SNAKE_NUM 10
#define LADDER_NUM 7

typedef struct board Board;

Board* new_board(int snakes_array[2][SNAKE_NUM], int ladder_array[2][LADDER_NUM]);

int is_ladder(Board * board, int coord);

int is_snake(Board * board, int coord);

void set_player_coordinate(Board* board, int coord_prev,int coord_next, int player_num);

#endif
