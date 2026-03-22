/******************************************************************************
 *  Description     : Handles the game logic and mechanics of Mantis
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
 * Ask the user how many players will be playing
 * 
 * @param numGamePlayers Where the users input will be stored
 */
void getNumPlaying(int *numGamePlayers)
{
    do{
        printf("How many players? ");
        scanf("%d", numGamePlayers);
        while(getchar() != '\n');

        if(*numGamePlayers < MIN_GAME_PLAYERS || *numGamePlayers > MAX_GAME_PLAYERS)
            printf("Invalid input. Minimum of %d players and maximum of %d players\n\n", MIN_GAME_PLAYERS, MAX_GAME_PLAYERS);

    }while(*numGamePlayers < MIN_GAME_PLAYERS || *numGamePlayers > MAX_GAME_PLAYERS);
}

/**
 * Check if a username exists
 * 
 * @param players The array of registered players
 * @param numPlayers Number of registered players
 * @param name The username to check
 * 
 * @return 1 if username exits, 0 otherwise
 */
int usernameExists(Player players[], int numPlayers, User name)
{
    int i;
    int exists = 0;

    for(i = 0; i < numPlayers; i++)
        if(strcmp(name, players[i].name) == 0)
            exists =1;

    return exists;
}

/**
 * 
 */
void registerPlayer()
{

}

/**
 * Let's user select the players who will be playing
 * 
 * @param players The array of registered players
 * @param numPlayers Number of registered players
 * @param gamePlayes The array where the players playing will be stored
 * @param numGamePlayers Number of players playing
 */
void playerSelection(Player players[], int numPlayers, GamePlayer gamePlayers[], int numGamePlayers)
{
    int registered; // 1 if player has been successfully registered
    int numSelected = 0; // the number of players that has been selected
    int choice;
    int i, j;

    //set picked variable in players to 0
    for(i = 0; i < numPlayers; i++)
        players[i].picked = 0;

    while(numSelected < numGamePlayers) 
    {
        system("cls");

        //show which player is Player n and which slots are empty
        for(i = 0; i < numGamePlayers; i++)
        {
            if(i < numSelected)
                printf("P%d: %s\n", i+1, gamePlayers[i].player->name);
            else 
                printf("P%d: ?\n", i+1);
        }

        printf("\nSelect Player %d:\n", numSelected + 1);
        printf("\t[0] Add new player\n");

        //show the players they can select
        for(i = 0; i < numPlayers; i++)
        {
            if(players[i].picked == 1)
            {
                printf("\t[%d] %s ", i+1, players[i].name);
                iSetColor(I_COLOR_GREEN);
                printf("(Already selected)\n");
                iSetColor(I_COLOR_WHITE);
            }
            else
                printf("\t[%d] %s\n", i+1, players[i].name);
        }

        //ask user
        printf("\n>> ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        if(choice == 0)
        {
            registerPlayer();

            if(registered == 1)
            {
                players[numPlayers - 1].picked = 1;
                gamePlayers[numSelected].player = &players[numPlayers - 1];
                numSelected++;
            }
        }
        else if(choice >= 1 && choice <= numPlayers)
        {
            if(players[choice-1].picked == 1)
            {
                printf("\nThat player is already selected. Try again.\n");
                pressAnyKey();
            }
            else
            {
                players[choice-1].picked = 1;
                gamePlayers[numSelected].player = &players[choice-1];
                numSelected++;
            }
        }
        else
        {
            printf("Invalid input. Try again.\n");
            pressAnyKey();
        }
    }

   //initialize gamePlayer tank
    for(i = 0; i < numGamePlayers; i++)
        for(j = 0; j < 7; j++)
        {
            gamePlayers[i].tank[j] = 0;
            gamePlayers[i].tankPoints[j] = 0;
            gamePlayers[i].score = 0;
        }
}

/**
 * 
 */
int hasColor()
{

}

/**
 * 
 */
int getColorIndex()
{

}

/**
 * 
 */
Card drawCard()
{

}

/**
 * 
 */
void addToTank()
{

}

/**
 * 
 */
void shuffleAndDeal()
{

}

/**
 * 
 */
void tryToScore()
{

}

/**
 * 
 */
void tryToSteal()
{

}

/**
 * 
 */
void displayGameState()
{

}

/**
 * 
 */
int checkWinner()
{

}

/**
 * 
 */
void showResults()
{

}

/**
 * 
 */
void gameStart()
{

}