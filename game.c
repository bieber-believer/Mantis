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
 * 
 */
int usernameExists()
{

}

/**
 * 
 */
void registerPlayer()
{

}

/**
 * 
 */
void playerSelection()
{

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