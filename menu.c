/******************************************************************************
 *  Description     : Handles the functions for the main menu
 *  Author/s        : Dy, Jasmine Yzabelle
 *  Section         : S22A
 *  Last Modified   : March 22, 2026
 ******************************************************************************/

/* ----- preprocessor directives ----- */
#include <stdio.h>
#include <string.h>

#include "defsDy.h"

/* ----- function implementation ----- */

/**
 * 
 */
void newGame()
{

}

/**
 * Display the tutorial of Mantis
 */
void displayHowToPlay()
{
    printf("The cards in Mantis are two sided. Each card has three different colors\n");
    printf("on the back and only one color on the front. One of the three colors on the back\n");
    printf("of the card is the color that in on the front of the card.\n\n");

    printf("To start the turn, you have to choose between one of the two actions:\n");
    iSetColor(I_COLOR_CYAN);
    printf("-Try to Score\n-Try to Steal\n\n");
    iSetColor(I_COLOR_WHITE);

    printf("When you decide to try and score, you will draw the top card from the Draw Pile.\n");
    printf("Flip the card over and put it in your Tank. If the new card matches any existing card(s)\n");
    printf("in your Tank, add the new card and all matching color cards to your Score Pile.\n");
    printf("If the card does not match any of the cards already in your Tank, add it.\n\n");

    printf("Your other option is to try to steal. First, decide which player you'll try to steal from.\n");
    printf("Then, flip over the top card from the Draw Pile. If the new card's color corresponds to one or\n");
    printf("more cards in the chosen player's Tank, place the new card and any matching cards in your own\n");
    printf("Tank. If the card does not match any of the cards in front of the chosen player, you will place the\n");
    printf("new card in the chosen player's Tank.\n\n");

    iSetColor(I_COLOR_GREEN);
    printf("The first player to get a score higer or equal to the winning points win.\n\n");
    iSetColor(I_COLOR_WHITE);

    printf("Source: https://www.geekyhobbies.com/mantis-rules/ \n");
}

/**
 * Sorts players by their wins in descending order
 * 
 * @param players The array with all the registered players
 * @param topWins The array where the sorted players will be stored
 * @param numPlayers Number of registered players
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
 * Sorts players by their score in descending order
 * 
 * @param players The array with all the registered players
 * @param topScore The array where the sorted players will be stored
 * @param numPlayers Number of registered players
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
 * Displays the top 10 Players with the most amount of wins
 * 
 * @param topWins The array with the sorted players based on the most amount of wins
 * @param numPlayers Number of registered players
 */
void displayTop10Wins(Player topWins[], int numPlayers)
{
    int i;

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
 * Displays the top 10 players with the highest score
 * 
 * @param topScore The array with the sorted players by highest score
 * @param numPlayers Number of registered players
 */
void displayTop10Score(Player topScore[], int numPlayers)
{
    int i;

    printf("Top 10 Players with the highest score:\n\n");
    printf("------------------------------------------------------------------\n");
    printf("%-10s %-36s %-10s %-10s\n", "Rank", "Username", "Wins", "Score");
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
 * Asks user how they want to view the top 10 players then displays the top 10 of their chosen choice
 * 
 * @param players The array of registered players
 * @param topWins The array of players sorted by most to least wins
 * @param topScore The array of players sorted by highest to lowest score
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
            printf("No player has played :(\n");
            pressAnyKey();
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
                    displayTop10Wins(topWins, numPlayers);
                    pressAnyKey();
                    loop = 0; // user goes back to main menu
                    break;
                case 2:
                    system("cls");
                    sortByScore(players, topScore, numPlayers);
                    displayTop10Score(topScore, numPlayers);
                    pressAnyKey();
                    loop = 0; // user goes back to main menu
                    break;
                case 0:
                    loop = 0;
                    break;
                default:
                    printf("Invalid input. Try again.\n");
                    pressAnyKey();
            }
        }
    }
}

/**
 * Allows the user to change the settings of the game
 * 
 * @param currSettings The settings they wish to change
 * 
 * @pre initRandom() has been called already
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
        printf("(Default: Random)\n\n"); 

        iSetColor(I_COLOR_CYAN);
        printf("Change Settings?\n");
        iSetColor(I_COLOR_WHITE);
        printf("[1] Winning Points\n");
        printf("[2] Shuffle Seed\n");
        printf("[3] Reset to Default\n");
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
            case 3:
                currSettings->winningPoints = 20;
                currSettings->seed = randomInt();
                pressAnyKey();
                break;
            case 0:
                loop = 0;
                break;
            default:
                printf("Invalid input. Try again.\n");
                pressAnyKey();
        }
    }
}

/**
 * 
 */
void displayAcknowledgements()
{

}

/**
 * 
 */
void mainMenu()
{

}