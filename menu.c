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
 * Sorts the players by their wins in descending order
 * 
 * @param players The array with all the players
 * @param topWins The array where the top 10 players will be stored
 * @param numPlayers The number of players that are registered
 */
void sortByWins(Player players[], Player topWins[], int numPlayers)
{
    int i, j, max;
    Player temp;

    //put all the registered players in topWins
    for(i = 0; i < numPlayers; i++)
        topWins[i] = players[i];

    //start sorting
    for(i = 0; i < numPlayers - 1; i++)
    {
        max = i;

        for(j= i + 1; j < numPlayers; j++)
        {
            if(players[j].wins > players[max].wins)
            max = j;
        }

        if(max != i)
        {
            temp = topWins[i];
            topWins[i] = topWins[max];
            topWins[max] = temp;
        }
    }
}

/**
 * Sorts the players by their score in descending order
 * 
 * @param players The array with all the players
 * @param topScore The array where the top 10 players will be stored
 * @param numPlayers The number of players that are registered
 */
void sortByScore(Player players[], Player topScore[], int numPlayers)
{

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
 * Asks user how they wanna view the top 10 players
 */
void displayTop10()
{
    
}

/**
 * Allows the user to change the wining points and shuffle seed
 * 
 * @param currSettings The current game settings to be changed
 */
void changeSettings(Settings *currSettings)
{
    int loop = 1;
    int choice;

    while(loop == 1)
    {
        system("cls");
        printf("Settings:\n");
        printf("Winning Points: %d points ", currSettings->winningPoints);
        printf("(Default: 20 points)\n");
        printf("Shuffle Seed: %d ", currSettings->seed);
        printf("(Default: Random)\n"); 

        printf("Change Settings?\n");
        printf("[1] Winning Points\n");
        printf("[2] Shuffle Seed\n");
        printf("[0] Back to Main Menu\n\n");
        printf(">> ");
        scanf("%d", &choice);
        while(getchar() != '\n');
      
        switch (choice)
        {
            case 1:
                printf("\nNew Winning Points?\n");
                printf(">> ");
                scanf("%d", &currSettings->winningPoints);
                while(getchar() != '\n');
                break;
            case 2:
                printf("\nNew Shuffle Seed?\n");
                printf(">> ");
                scanf("%d", &currSettings->seed);
                while(getchar() != '\n');
                break;
            case 0:
                loop = 0;
                break;
            default:
                printf("Invalid input. Try again.\n");
                while(getchar() != '\n');
                printf("Press any key...\n");
                getchar();
                break;
        }
    }
}

/**
 * The main menu of the game
 * 
 * @param currSetting The current game settings
 */
void mainMenu(Settings *currSettings)
{
    int loop = 1; // variable to keep the loop going
    int choice;  // where users choice will be stored
    while(loop == 1)
    {
        system("cls");
        displayTitle();
        printf("Main Menu\n");
        printf("[1] New Game\n");
        printf("[2] Top Players\n");
        printf("[3] Settings\n");
        printf("[0] Exit\n\n");

        printf(">> ");
        scanf("%d", &choice);
        while(getchar() != '\n');

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
                changeSettings(currSettings);
                break;
            case 0:
                printf("May the force be with you. Bye!");
                loop = 0; // set loop to 0 to break out the loop
                break;
            default:
                printf("Invalid input. Try again.");
                printf("Press any key...\n");
                getchar();
        }
    }
}