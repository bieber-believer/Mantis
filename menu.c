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
 * 
 */
void displayTop10Wins()
{

}

/**
 * 
 */
void displayTop10Score()
{

}

/**
 * 
 */
void displayTop10()
{

}

/**
 * 
 */
void changeSettings()
{

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