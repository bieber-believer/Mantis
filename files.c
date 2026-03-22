/******************************************************************************
 *  Description     : Handles the functions for file processing
 *  Author/s        : Dy, Jasmine Yzabelle
 *  Section         : S22A
 *  Last Modified   : March 22, 2026
 ******************************************************************************/

/* ----- preprocessor directives ----- */
#include <stdio.h>

#include "defsDy.h"

/* ----- function implementation ----- */

/**
 * Reads the mantis.txt file and stores it in a struct array
 * 
 * @param deck The array where the cards will be stored
 */
void mantisToStruct(Card deck[])
{
    int i;
    FILE *fp;
    fp = fopen("mantis.txt", "r");

    for(i = 0; i < TOTAL_CARDS; i++){
        fscanf(fp," %c | %3s %d", &deck[i].front, deck[i].back, &deck[i].point);
    }

    fclose(fp);
}

/**
 * Read the players.txt file and store it in a struct array
 * 
 * @param players The array where the registered players will be stored
 * @param numPlayers The pointer that will update the number of registered players
 */
void playersToStruct(Player players[], int *numPlayers)
{
    int i;
    FILE *fp;

    fp=fopen("players.txt", "r");

    for(i = 0; i < MAX_PLAYERS && feof(fp) == 0; i++){
        if(fscanf(fp, "%s %d %d", players[i].name, &players[i].wins, &players[i].highestScore) == PLAYER_INFO)
        *numPlayers += 1;
    }

    fclose(fp);
}

/**
 * Saves current update of all registered players to player.txt
 * 
 * @param The array of all registered players
 * @param The number of registered players
 */
void savePlayers(Player players[], int numPlayers)
{
    int i;
    FILE *fp;

    fp = fopen(PLAYER_FILE, "w");

    for(i = 0; i < numPlayers; i++)
        fprintf(fp, "%s %d %d\n", players[i].name, players[i].wins, players[i].highestScore);

    fclose(fp);
}