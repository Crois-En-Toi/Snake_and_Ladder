#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#include "snake_and_ladder.h"
#include "board.h"

#define NAME 100

int snake_cords[2][SNAKE_NUM] = {{98,85,80,74,71,49,35,30,28,21},
                                   {16,12,50,30,40,5,15,10,18,2}};
int ladder_cords[2][LADDER_NUM]= {{14,17,24,38,53,60,70}
                                 ,{51,63,78,52,69,83,89}};


char player1[NAME];
char player2[NAME];
char password[NAME];


//Main snake and ladder logic functions 
void start_game()
{
    printf("creating a board to play\n");
    Board *game_board = new_board(snake_cords,ladder_cords);

    display_board(game_board);
    printf("\n");
    printf("The Game is Starting .. ... .. .\n");
    printf("\n\n");

    int player1_position=0;
    int player2_position=0;
    set_player_coordinate(game_board, 0 ,0 ,1);
    set_player_coordinate(game_board, 0 ,0 ,2);
    
    while((player1_position==100) || (player2_position==100))
    {
        //todo
    }

    
}

void display_userlogin()
{   
    
    char Global_password[]="1234"; 
    
    printf("The game is about to start pls enter the names of players\n");
    printf("Enter the name of player1  \n");
    scanf("%s",player1);
    printf("player1 named as %s is registered\n",player1);
    
    printf("Enter the name of player2 \n");
    scanf("%s",player2);
    printf("player2 named as %s is registered\n",player2);
    
    


    printf("==============\n");
    printf("     LOGIN    \n");
    printf("==============\n");
    printf("Enter game password to start\n");
    scanf("%s",password);
    

    while(strcmp(password,Global_password)!=0)
    {   
        printf("Entered password is wrong please retry\n");
        scanf("%s",password);
    }
    
    start_game();

    
}

void display_board(Board *board)
{
    //borders
    for(int i=0; i<10; i++)
    {
        printf("--------");
    }
    printf("\n");
    for(int i=0; i<100; i++)
    {
        if(is_snake(board, i))
        {
            printf("~~*\t");
        }
        else if(is_ladder(board, i))
        {
            printf("\\-\\\t");
            
        }
        else{
            printf("%d\t", i);
        }
        if((i+1)%10==0 && i!=0)
        {
            printf("\n");
        }
    }
      //borders
    for(int i=0; i<10; i++)
    {
        printf("--------");
    }
    printf("\n");
}
















