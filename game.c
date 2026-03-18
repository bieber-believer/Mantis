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
            printf("Invalid input. Minimum of %d players and maximum of %d players\n", MIN_GAME_PLAYERS, MAX_GAME_PLAYERS);

    }while(*numGamePlayers < MIN_GAME_PLAYERS || *numGamePlayers > MAX_GAME_PLAYERS);
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
void playerSelection()
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