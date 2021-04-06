#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "board.h"

void test_board();

int ladder_cords[2][4];
int snake_cords[2][4];


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
    //pointing snake mouth
    snake_cords[0][0]=98;
    snake_cords[0][1]=88; 
    snake_cords[0][2]=44; 
    snake_cords[0][3]=66;   
    //pointing snake tail
    snake_cords[1][0]=14;
    snake_cords[1][1]=25; 
    snake_cords[1][2]=39; 
    snake_cords[1][3]=10;   
  
    //pointing ladder start
    ladder_cords[0][0]=3;
    ladder_cords[0][1]=28; 
    ladder_cords[0][2]=80; 
    ladder_cords[0][3]=36;   
    //pointing ladder end
    ladder_cords[1][0]=97;
    ladder_cords[1][1]=40; 
    ladder_cords[1][2]=90; 
    ladder_cords[1][3]=52;   
 

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












