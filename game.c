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
    int i;
    int exists = 0;

    for(i = 0; i < numPlayers; i++)
        if(strcmp(name, players[i].name) == 0)
            exists =1;

    return exists;
}

/**
 * Registers a new player to a Players array and add them to players.txt
 * 
 * @param players The array of registered players
 * @param numPlayers The number of reigstered players that will be updated
 */
void registerPlayer(Player players[], int *numPlayers)
{
    int i;
    int loop = 1, exists = 0;
    FILE *fp;
    User newUsername;

    while(loop == 1)
    {   
        if(*numPlayers >= MAX_PLAYERS)
        {
            printf("Can't register. Max number of players reached.\n");
            loop = 0;
        }
        else
        {
            printf("Enter username (max 36 characters): ");
            scanf("%36s", newUsername);
            while(getchar() != '\n');

            //check if it exists
            exists = usernameExists(players, *numPlayers, newUsername);

            if(exists == 1)
                printf("Username already exists. Try again.\n");
            else
            {
                //add to array
                strcpy(players[*numPlayers].name, newUsername);
                players[*numPlayers].wins = 0;
                players[*numPlayers].highestScore = 0;

                //add to txt file
                fp = fopen(PLAYER_FILE, "a");
                fprintf(fp, "%s %d %d", newUsername, 0, 0);
                fclose(fp);

                //update the number of players
                *numPlayers += 1;
                printf("%s registered! Welcome!\n", newUsername);

                //exit loop
                loop = 0;
            }
        }
    }
}

/**
 * Let's the user select which players will be playing
 * 
 * @param players The array of reigstered players
 * @param numPlayers The number of registered players
 * @param gamePlayers The array where players who will be playing will be stored
 * @param numGamePlayers The number of players playing
 */
void playerSelection(Player players[], int numPlayers, GamePlayer gamePlayers[], int numGamePlayers)
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