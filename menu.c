/******************************************************************************
 *  Description     : This function handles the menu and player selection
 *  Author/s        : <student1 full name (last name, first name)>
 *                    <student2 full name (last name, first name)>
 *  Section         : S22A
 *  Last Modified   : March 16, 2026
 ******************************************************************************/

 /* ----- preprocessor directives ----- */
#include <stdio.h>

#include "defs.h"
#include "helpers_1.c"
#include "helpers_2.c"
#include "game.c"

//===========================================
//          Function Implementation
//===========================================

/**
 * Display the title
 */
void displayTitle()
{
    printf("Mantis\n\n");
}

/**
 * Compiles the functions needed for a new game
 */
void newGame()
{
    //call playerSelection()
    //call gameStart()
}

/**
 * Display the top 10 Players with the highest win  
 */
void displayTop10ByWins()
{

}

/**
 * Display the top 10 Players with the highest score  
 */
void displayTop10ByScore()
{

}

/**
 * Allows the user to change the wining points and shuffle seed
 */
void changeSettings()
{

}

/**
 * The main menu of the game
 */
void mainMenu()
{
    int loop = 1; // variable to keep the loop going
    int choice;  // where users choice will be stored
    while(loop == 1)
    {
        fflush(stdin); //clear the stream
        displayTitle();
        printf("Main Menu\n");
        printf("[1] New Game\n");
        printf("[2] Top Players\n");
        printf("[3] Settings\n");
        printf("[0] Exit\n\n");

        printf(">> ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                newGame();
                break;
            case 2:
                displayTop10();
                printf("Press any key...\n");
                getchar();
                break;
            case 3:
                changeSettings();
                printf("Press any key...\n");
                getchar();
                break;
            case 0:
                printf("May the force be with you. Bye!");
                loop = 0; // set loop to 0 to break out the loop
        }
    }
}