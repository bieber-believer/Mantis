/******************************************************************************
 *  Description     : Mantis but C
 *  Author/s        : <student1 full name (Dy, Jasmine Yzabelle)>
 *                    <student2 full name (last name, first name)>
 *  Section         : S22A
 *  Last Modified   : March 16, 2026
 *  Acknowledgments : https://www.geeksforgeeks.org/c/format-specifiers-in-c/
 *                    https://www.geekyhobbies.com/mantis-rules/ 
 *                    https://boxes.thomasjensen.com/box-designs.html
 *                    https://patorjk.com/software/taag/#p=display&f=Star+Wars&t=MANTIS&x=none&v=4&h=4&w=80&we=false
 *                    https://asciiart.website/art/5899
 ******************************************************************************/

/* ----- preprocessor directives ----- */
#include <stdio.h>

#include "defs.h"
#include "helpers_1.c"
#include "helpers_2.c"
#include "interface.c"
#include "game.c"
#include "menu.c"

/* ----- definitions (i.e., constants, typedefs, structs) ----- */
//i inserted my own definitions in defs.h

/* ----- function implementations ----- */
//my function protoypes are in defs.h

/**
 * Reads the mantis.txt file and stores it in a struct
 * 
 * @param deck The struct array where the cards will be stored
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
 * Read the players.txt file and store it in a struct
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

/**
 *  Computes the average of the non-negative numbers from a given list of numbers
 *  @param arr The starting address of the array containing the list of numbers
 *  @param arrSize The size of the array
 *  @return The average of the non-negative numbers from the list of numbers
 *  @pre arr can include positive numbers, negative numbers, and zeros
 *  @pre arrSize is the correct size of arr
 */
float getAverage(int arr[], int arrSize)
{
  float average;
  int sum = 0, n = 0, i;

  for (i = 0; i < arrSize; i++)
    if (arr[i] >= 0)
    {
      sum += arr[i];
      n++;
    }

  if (n == 0) // prevent divide by zero
    average = 0;
  else
    average = sum / (float)n;

  return average;
}

int main()
{
  /* your project code */
  Player players[MAX_PLAYERS] = {0};  // array of players
  int numPlayers = 0;           // number of registered players

  Player topWins[MAX_PLAYERS]; //array that has the list of players from highest wins to lowest
  Player topScore[MAX_PLAYERS]; //array that has the list of players from the highest score to lowest

  Card deck[TOTAL_CARDS];      // array of cards
  int deckSize;              // the size of the deck

  GamePlayer gamePlayers[MAX_GAME_PLAYERS]; // array of the players currently playing
  int numGamePlayers = 0;                   // number of players playing

  Settings currSettings;                   // current settings of the game
  currSettings.winningPoints = 20;         // default points needed to win the game
  initRandom();                            // initialize the random number generator
  currSettings.seed = randomInt();        // default seed value

  //load data from files
  mantisToStruct(deck);
  playersToStruct(players, &numPlayers);

  //call main menu
  mainMenu(players, topWins, topScore, &numPlayers, gamePlayers, &currSettings, &numGamePlayers, deck, &deckSize);

  return 0;
}

/**
 * This is to certify that this project is my/our own work, based on my/our personal
 * efforts in studying and applying the concepts learned. I/We have constructed the
 * functions and their respective algorithms and corresponding code by myself/ourselves.
 * The program was run, tested, and debugged by my/our own efforts. I/We further certify
 * that I/we have not copied in part or whole or otherwise plagiarized the work of other
 * students and/or persons, nor did I employ the use of AI in any part of the deliverable.
 *
 * <student1 full name (Dy, Jasmine Yzabelle)> (DLSU ID# 12504254)
 * <student2 full name (last name, first name)> (DLSU ID# <number>)
 */
