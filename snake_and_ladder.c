#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "snake_and_ladder.h"
#include "board.h"

#define NAME 100


int snake_cords[2][SNAKE_NUM] = {{98, 85, 80, 74, 71, 49, 35, 30, 28, 21},
                                 {16, 12, 50, 30, 40, 5, 15, 10, 18, 2}};
int ladder_cords[2][LADDER_NUM] = {{14, 17, 24, 38, 53, 60, 70},
                                   {51, 63, 78, 52, 69, 83, 89}};
void main_logic(Board *gboard);

char player1[NAME];
char player2[NAME];
char password[NAME];

int user_input;
int player1_position = 0;
int player2_position = 0;
int player_turn = 0;
int roll_value;

//Main snake and ladder logic functions

//This function is called when game is about to start
void start_game()
{
    //DO NOT EVER TOUCH THIS
    //DANGER ALERT NOT TO BE MESSED AROUND
    //WE DON'T KNOW WHAT IT DOES BUT IT IS ESSENTIAL
    FILE *file_ptr;
    file_ptr = fopen("log.txt", "w");
    fclose(file_ptr);
    //OK NOW PROCEED

    printf("creating a board to play\n");
    Board *game_board = new_board(snake_cords, ladder_cords);

    display_board(game_board);
    printf("\n");
    printf("The Game is Starting .. ... .. .\n");
    printf("\n\n");

    set_player_coordinate(game_board, 0, 0, 1);
    set_player_coordinate(game_board, 0, 0, 2);

    input_log(1, game_board);
    input_log(2, game_board);

    while ((player1_position != 99) && (player2_position != 99))
    {
        //todo
        if (user_input == 3)
        {
            exit(0);
        }
        if (player_turn == 0)
        {
            printf("ITS YOUR TURN %s\n", player1);
            display_board(game_board);
            display_gameview();
            scanf("%d", &user_input);

            main_logic(game_board);

            input_log(1, game_board);
            player_turn++;
        }
        else
        {
            printf("ITS YOUR TURN %s\n", player2);
            display_board(game_board);
            display_gameview();
            scanf("%d", &user_input);
            main_logic(game_board);

            input_log(2, game_board);
            player_turn--;
        }

        printf("\n\n");
        printf("Position of Player1: %d\n", player1_position);
        printf("Position of Player2: %d\n", player2_position);
    }

    if (player1_position == 99)
    {
        printf("%s is the winner \n", player1);
    }
    else
    {
        printf("%s is the winner \n", player2);
    }
}

//login functionality
void display_userlogin()
{
    //This is the global password 
    char Global_password[] = "1234";

    printf("The game is about to start pls enter the names of players\n");
    printf("Enter the name of player1  \n");
    scanf("%s", player1);
    printf("player1 named as %s is registered\n", player1);

    printf("Enter the name of player2 \n");
    scanf("%s", player2);
    printf("player2 named as %s is registered\n", player2);

    printf("==============\n");
    printf("     LOGIN    \n");
    printf("==============\n");
    printf("Enter game password to start\n");
    scanf("%s", password);

    while (strcmp(password, Global_password) != 0)
    {
        printf("Entered password is wrong please retry\n");
        scanf("%s", password);
    }

    start_game();
}

//displays the real time board
void display_board(Board *board)
{
    //borders
    for (int i = 0; i < 10; i++)
    {
        printf("--------");
    }
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        if ((player1_position == player2_position) && (i == player1_position))
        {
            printf("%c%c||%c%c ", player1[0], player1[1], player2[0], player2[1]);
        }
        else if (player1_position == i)
        {
            printf("(%c%c)\t", player1[0], player1[1]);
        }
        else if (player2_position == i)
        {
            printf("(%c%c)\t", player2[0], player2[1]);
        }
        else if (is_snake(board, i))
        {
            printf("~~*\t");
        }
        else if (is_ladder(board, i))
        {
            printf("\\-\\\t");
        }
        else
        {
            printf("%d\t", i);
        }
        if ((i + 1) % 10 == 0 && i != 0)
        {
            printf("\n");
        }
    }
    //borders
    for (int i = 0; i < 10; i++)
    {
        printf("--------");
    }
    printf("\n");
}

//Tells the roll value
int roll_dice()
{
    return 1 + rand() % 6;
}

//game menu
void display_gameview()
{
    printf("=============\n");
    printf("1.Roll Dice\n");
    printf("2.print Log\n");
    printf("3.Exit :/\n");
}

//This is the core or main logic
void main_logic(Board *gboard)
{
    if (player_turn == 0)
    {
        if (user_input == 1)
        {
            roll_value = roll_dice();
            roll_value = player1_position + roll_value;
            if (roll_value > 99)
            {
                roll_value = player1_position;
            }
            else if (is_snake(gboard, roll_value))
            {
                //input_log(1, gboard);
                printf("%s got BIT BY SNAKE at %d fell to %d\n", player1,roll_value,get_snake_tail(gboard,roll_value));
                set_player_coordinate(gboard, player1_position, get_snake_tail(gboard, roll_value), 1);
                player1_position = get_snake_tail(gboard, roll_value);
            }
            else if (is_ladder(gboard, roll_value))
            {
                //input_log(1, gboard);
                printf("%s TOOK a LADDER at %d climed up to %d\n", player1,roll_value,get_ladder_end(gboard,roll_value));
                set_player_coordinate(gboard, player1_position, get_ladder_end(gboard, roll_value), 1);
                player1_position = get_ladder_end(gboard, roll_value);
            }
            else
            {
                set_player_coordinate(gboard, player1_position, roll_value, 1);
                player1_position = roll_value;
            }
        }
        else if (user_input == 2)
        {
            //printf("USER INPUT 2 HOGYA HAI BUT MEI PRINT NI KAREGA\n");
            print_log();
        }
        else if (user_input == 3)
        {
            printf("%s Quit %s Won!!!\n", player1, player2);
        }
    }
    else
    {
        if (user_input == 1)
        {
            roll_value = roll_dice();
            roll_value = player2_position + roll_value;
            if (roll_value > 99)
            {
                roll_value = player2_position;
            }
            else if (is_snake(gboard, roll_value))
            {
                printf("%s got bit BY SNAKE at %d fell to %d\n", player2,roll_value,get_snake_tail(gboard,roll_value));
                set_player_coordinate(gboard, player2_position, get_snake_tail(gboard, roll_value), 2);
                player2_position = get_snake_tail(gboard, roll_value);
            }
            else if (is_ladder(gboard, roll_value))
            {
                printf("%s TOOK a LADDER at %d climed up to %d\n", player2,roll_value,get_ladder_end(gboard,roll_value));
                set_player_coordinate(gboard, player2_position, get_ladder_end(gboard, roll_value), 2);
                player2_position = get_ladder_end(gboard, roll_value);
            }
            else
            {
                set_player_coordinate(gboard, player2_position, roll_value, 1);
                player2_position = roll_value;
            }
        }

        else if (user_input == 2)
        {
            print_log();
        }
        else if (user_input == 3)
        {
            printf("%s Quit %s Won!!!\n", player2, player1);
        }
    }
}
//prints log stored in log.txt
void print_log()
{

    FILE *file_pointer;
    char s;
    file_pointer = fopen("log.txt", "r");
    if (file_pointer == NULL)
    {
        printf("\nCAN NOT OPEN FILE");
        exit(0);
    }

    s = getc(file_pointer);
    while (s != EOF)
    {
        printf("%c", s);
        s = getc(file_pointer);
    }
    printf("\n");

    fclose(file_pointer);
}
//places the log in log.txt
void input_log(int player_num, Board *gboard)
{
    FILE *file_ptr = fopen("log.txt", "a");
    if (file_ptr == NULL)
    {
        printf("Log file can not be opened continuing game without log\n");
    }

    char sentence[5000] = " Moved to coordinate ";
    int pos;
    char *Name;
    if (player_num == 1)
    {
        pos = player1_position;
        Name = player1;
        if (is_snake(gboard, roll_value))
        {
            snprintf(sentence, 1000, "%s got bit by snake!! at %d fell to %d\n", Name, roll_value, get_snake_tail(gboard, roll_value));
            fputs(sentence, file_ptr);
        }
        if (is_ladder(gboard, roll_value))
        {
            snprintf(sentence, 1000, "%s got a Ladder!! at %d climbed up to %d\n", Name, roll_value, get_ladder_end(gboard, roll_value));
            fputs(sentence, file_ptr);  
        }
    }
    else
    {
        pos = player2_position;
        Name = player2;
        if (is_snake(gboard, roll_value))
        {
            snprintf(sentence, 1000, "%s got bit by snake!! at %d fell to %d\n", Name, roll_value, get_snake_tail(gboard, roll_value));
            fputs(sentence, file_ptr);
        }
        if (is_ladder(gboard, roll_value))
        {            
            
            snprintf(sentence, 1000, "%s got a Ladder!! at %d climbed up to %d\n", Name, roll_value, get_ladder_end(gboard, roll_value));
            fputs(sentence, file_ptr);
        }
    }
    snprintf(sentence, 1000, "%s moved to coordinate: %d", Name, pos);
    fputs(sentence, file_ptr);
    fputs("\n", file_ptr);

    if (player_num == 2)
    {
        fputs("\n\n", file_ptr);
    }

    fclose(file_ptr);
}
