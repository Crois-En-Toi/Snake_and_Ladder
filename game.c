/* Date: 4/04/21
   Main Game file which would run the game
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "snake_and_ladder.h"
#include "board.h"

void display();
void how_to_play();

int main()
{
   int menu=0;
   while (menu != 1)
   {
      //start cover title of the game
      display();
      scanf("%d", &menu);
      printf("\n");

      //take user input whether to play or know how to play
      if (menu == 3)
      {
         return 0;
      }
      else if(menu == 2)
      {
         how_to_play();
      }
      else
        {
            display_userlogin();
        }
   }

   
}

//cover title start game and how to play
void display()
{
   //print cover title
   printf("\n");
   printf("================================\n");
   printf("        SNAKE_AND_LADDER        \n");
   printf("================================\n");
   printf("\n");
   printf("MENU :\n");
   printf("1. Start\n");
   printf("2. How to play\n");
   printf("3. Exit\n");
   printf("\nEnter Input: ");
}

void how_to_play()
{

   FILE *file_pointer;
   char s;
   file_pointer = fopen("HELP.txt", "r");
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

