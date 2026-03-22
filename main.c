/******************************************************************************
 *  Description     : Mantis but C
 *  Author/s        : Dy, Jasmine Yzabelle
 *  Section         : S22A
 *  Last Modified   : March 22, 2026
 *  Acknowledgments : https://www.geekyhobbies.com/mantis-rules/ 
 *                    https://boxes.thomasjensen.com/box-designs.html
 *                    https://patorjk.com/software/taag/#p=display&f=Star+Wars&t=MANTIS&x=none&v=4&h=4&w=80&we=false
 *                    https://asciiart.website/art/5899
 ******************************************************************************/

/* ----- preprocessor directives ----- */
#include <stdio.h>

#include "defsDy.h"
#include "helpers_2.c"
#include "interface.c"
#include "files.c"
#include "menu.c"
#include "game.c"
#include "design.c"

int main()
{
    //variables
    Player players[MAX_PLAYERS];                // array of all registered players
    int numPlayers = 0;                         // number of registered players

    Player topWins[MAX_PLAYERS];                // array of players with most to least number of wins
    Player topScore[MAX_PLAYERS];               // array of players with the highest to lowest scores

    Card deck[TOTAL_CARDS];                     // deck of cards
    int deckSize = TOTAL_CARDS;                 // number of cards in deck

    GamePlayer gamePlayers[MAX_GAME_PLAYERS];   // array of players currently playing the game
    int numGamePlayers = 0;                     // number of players playing the game

    Settings currSettings;
    currSettings.winningPoints = 20;            // default winning points
    initRandom();
    currSettings.seed = randomInt();            // default seed

    //load data
    mantisToStruct(deck);
    playersToStruct(players, &numPlayers);

    //call mainMenu
    mainMenu(players, topWins, topScore, &numPlayers, &currSettings, gamePlayers, &numGamePlayers, deck, &deckSize);

    return 0;
}