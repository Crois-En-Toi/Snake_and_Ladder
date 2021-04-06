#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "board.h"

void test_board();

int snake_cords[2][SNAKE_NUM] = {{98,85,80,74,71,49,35,30,28,21},
       {16,12,50,30,40,5,15,10,18,2}};
int ladder_cords[2][LADDER_NUM]= {{14,17,24,38,53,60,70}
                                 ,{51,63,78,52,69,83,89}};


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

int main()
{
   printf("Started Test suit\n");
  
    test_board();

printf("all tests passed we are awesome!!!!!\n");


}

//Create a board
void test_board()
{   
    printf("Testing create board \n");

    Board *test_board = new_board(snake_cords,ladder_cords);
     int i=0 , j=0;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("This is tile %d,%d\n",i,j);
            printf("Cordinates : %d\n",test_board->game_board[i][j].coordinate);
            printf("snake Cordinates : %d \t %d\n",test_board->game_board[i][j].snake_start,test_board->game_board[i][j].snake_end);

            printf("ladder Cordinates : %d \t %d\n",test_board->game_board[i][j].ladder_start,test_board->game_board[i][j].ladder_end); 
            printf("hululululu %d\n",test_board->game_board[i][j].player1);  
            assert(test_board->game_board[i][j].player1==0);
        }
    }
}












