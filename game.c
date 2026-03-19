/******************************************************************************
 *  Description     : This file handle the functions when the game starts
 *  Author/s        : <student1 full name (Dy, Jasmine Yzabelle)>
 *                    <student2 full name (last name, first name)>
 *  Section         : S22A
 *  Last Modified   : March 16, 2026
 ******************************************************************************/

 /* ----- preprocessor directives ----- */
#include <stdio.h>

#include "defs.h"
#include "helpers_1.c"
#include "helpers_2.c"

//===========================================
//          Function Implementation
//===========================================

/**
 * Ask the user how many players will be playing
 * 
 * @param numGamePlayers Pointer where the users input will be stored
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
 * Checks if a username already exists
 * 
 * @param players The list of players
 * @param numPlayer The number of registered players
 * @param name The username to check
 * 
 * @return 1 if username exists, 0 otherwise
 */
int usernameExists(Player players[], int numPlayers, User name)
{

}

/**
 * Registers a new player
 */
void reigsterPlayer()
{

}

/**
 * Let's the user select which player will be playing
 */
void playerSelection(int numGamePlayers, int numPlayers)
{
    int i, j;

    getNumPlaying(&numGamePlayers);

    for(i = 0; i < numGamePlayers; i++)
    {
        printf("Select Player %d\n", i+1);
        printf("[0] Add new player");

        for(j = 0; j < numPlayers; j++)
            printf("[%d] %s\n", j+1);
    }
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

void shuffleAndDeal()
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
int checkWinner()
{

}

void gameStart()
{

}

void showResults()
{

}