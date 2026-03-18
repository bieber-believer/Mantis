/******************************************************************************
 *  Description     : This function handles the menu
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
            if(topWins[j].wins > topWins[max].wins)
            max = j;
        }

        if(i != max)
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
    int i, j, max;
    Player temp;

    //store the players in the top score
    for(i = 0; i < numPlayers; i++)
        topScore[i] = players[i];

    //start sorting
    for(i = 0; i < numPlayers - 1; i++)
    {
        max = i;

        for(j = i + 1; j < numPlayers; j++)
            if(topScore[j].highestScore > topScore[max].highestScore)
                max = j;
        
        if(i != max)
        {
            temp = topScore[i];
            topScore[i] = topScore[max];
            topScore[max] = temp;
        }
    }
}

/**
 * Display the top 10 Players with the highest win
 * 
 * @param players Array of all registered players
 * @param topWins Array where the sorted players get stored
 * @param numPlayers Number of registered players
 */
void displayTop10ByWins(Player players[], Player topWins[], int numPlayers)
{
    int i;

    sortByWins(players, topWins, numPlayers);

    printf("Top 10 Players with the highest wins:\n\n");
    printf("------------------------------------------------------------------\n");
    printf("%-10s %-36s %-10s %-10s\n", "Rank", "Username", "Wins", "Score");
    printf("------------------------------------------------------------------\n");

    if(numPlayers > 10)
    {
        for(i = 0; i < 10; i++)
        {
            printf("%-10d %-36s %-10d %-10d\n", i+1, topWins[i].name, topWins[i].wins, topWins[i].highestScore);
        }
    }
    else
    {
        for(i = 0; i < numPlayers; i++)
        {
            printf("%-10d %-36s %-10d %-10d\n", i+1, topWins[i].name, topWins[i].wins, topWins[i].highestScore);
        }
    }
}

/**
 * Display the top 10 Players with the highest score  
 * 
 * @param players Array of registered players
 * @param topScore Array where the sorted players gets stored
 * @param numPlayers Number of registered players
 */
void displayTop10ByScore(Player players[], Player topScore[], int numPlayers)
{
    int i;

    sortByScore(players, topScore, numPlayers);

    printf("Top 10 Players with the highest score:\n\n");
    printf("------------------------------------------------------------------\n");
    printf("%-10s %-36s %-10d %-10d\n", "Rank", "Username", "Wins", "Score");
    printf("------------------------------------------------------------------\n");

    if(numPlayers > 10)
    {
        for(i = 0; i < 10; i++)
        {
            printf("%-10d %-36s %-10d %-10d\n", i+1, topScore[i].name, topScore[i].wins, topScore[i].highestScore);
        }
    }
    else
    {
        for(i = 0; i < numPlayers; i++)
        {
            printf("%-10d %-36s %-10d %-10d\n", i+1, topScore[i].name, topScore[i].wins, topScore[i].highestScore);
        }
    }
}

/**
 * Asks user how they wanna view the top 10 players then displays the top 10 of their chosen choice
 * 
 * @param players Array of registered players
 * @param topWins Array where the players with the highest wins are stored in descending order
 * @param topScore Array where the players with the highest scores are stored in descending order
 * @param numPlayers Number of registered players
 */
void displayTop10(Player players[], Player topWins[], Player topScore[], int numPlayers)
{
    int loop = 1;
    int choice;

    while(loop == 1)
    {
        if(numPlayers == 0)
        {
            system("cls");
            printf("No player has played :(\n\n");
            printf("Press any key...\n");
            getchar();
            loop = 0;
        }
        else
        {
            system("cls");
            printf("View top players by:\n");
            printf("[1] Wins\n");
            printf("[2] Highest Score\n");
            printf("[0] Back to Main Menu\n\n");
            printf(">> ");
            scanf("%d", &choice);
            while(getchar() != '\n');

            switch(choice)
            {
                case 1:
                    system("cls");
                    displayTop10ByWins(players, topWins, numPlayers);
                    printf("\nPress any key to go back...\n");
                    getchar();
                    loop = 0; // user goes back to main menu
                    break;
                case 2:
                    system("cls");
                    displayTop10ByScore(players, topScore, numPlayers);
                    printf("\nPress any key to go back...\n");
                    getchar();
                    loop = 0; // user goes back to main menu
                    break;
                case 0:
                    loop = 0;
                    break;
                default:
                    printf("Invalid input. Try again.\n");
                    printf("\nPress any key to go back...\n");
                    getchar();
            }
        }
    }
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
                printf("Press any key...\n");
                getchar();
        }
    }
}

/**
 * The main menu of the game
 * 
 * @param currSetting The current game settings
 */
void mainMenu(Player players[], Player topWins[], Player topScore[], int numPlayers, Settings *currSettings)
{
    int loop = 1; // variable to keep the loop going
    int choice;  // where users choice will be stored
    while(loop == 1)
    {
        system("cls");
        displayTitle();
        printf("Main Menu\n");
        printf("[1] New Game\n");
        printf("[2] View Statistics\n");
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
                displayTop10(players, topWins, topScore, numPlayers);
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