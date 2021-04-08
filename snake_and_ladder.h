#ifndef SNAKE_AND_LADDER
#define SNAKE_AND_LADDER

#define SNAKE_NUM 10
#define LADDER_NUM 7
#include "board.h"

void display_userlogin();
void display_gameview();
void start_game();
void display_board(Board *board);
void print_log();
void input_log(int player_num, Board* gboard);
 

#endif
