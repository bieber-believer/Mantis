/******************************************************************************
 *  Description     : Mantis but C
 *  Author/s        : <student1 full name (Dy, Jasmine Yzabelle)>
 *                    <student2 full name (last name, first name)>
 *  Section         : S22A
 *  Last Modified   : March 16, 2026
 *  Acknowledgments : https://www.geeksforgeeks.org/c/format-specifiers-in-c/
 ******************************************************************************/

/* ----- preprocessor directives ----- */
#include <stdio.h>

#include "defs.h"
#include "helpers_1.c"
#include "helpers_2.c"

/* ----- definitions (i.e., constants, typedefs, structs) ----- */
//i inserted my own definitions in defs.h

/* ----- function implementations ----- */
#include "menu.c"
#include "game.c"

/**
 * Reads the mantis.txt file and stores it in a struct
 * 
 * @param deck The struct array where the cards will be stored
 * @param deckSize The pointer that will update the size of the deck
 */
void mantisToStruct(Card deck[], int *deckSize)
{
  int i;
  FILE *fp;
  fp = fopen("mantis.txt", "r");

  *deckSize = 0;

  for(i = 0; i < TOTAL_CARDS; i++){
    fscanf(fp," %c | %3s %d", &deck[i].front, deck[i].back, &deck[i].point);
    *deckSize += 1;
  }

  fclose(fp);
}

/**
 * Read the players.txt file and store it in a struct
 * 
 * @param players The struct array where the registered players will be stored
 * @param numPlayers The pointer that will update the number of registered players
 */
void playersToStruct(Player players[], int *numPlayers)
{
  int i;
  FILE *fp;

  fp=fopen("players.txt", "r");

  for(i = 0; i < MAX_PLAYERS; i++){
    fscanf(fp, "%s %d %d", players[i].name, &players[i].wins, &players[i].highestScore);
    *numPlayers += 1;
  }

  fclose(fp);
}
/**
 * 
 */
void savePlayers()
{
  
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
  Player players[MAX_PLAYERS];  // array of players
  int numPlayers = 0;           // number of registered players

  Player topWins[MAX_PLAYERS]; //array that has the list of players from highest wins to lowest
  Player topScore[MAX_PLAYERS]; //array that has the list of players from the highest score to lowest

  Card deck[TOTAL_CARDS];      // array of cards

  GamePlayer gamePlayers[MAX_GAME_PLAYERS]; // array of the players currently playing
  int numGamePlayers = 0;                   // number of players playing

  Settings currSettings;                   // current settings of the game
  currSettings.winningPoints = 20;         // default points needed to win the game
  initRandom();                            // initialize the random number generator
  currSettings.seed = randomInt();        // default seed value

  Card gameDeck[TOTAL_CARDS]; //the deck of cards that will be used in the game
  int gameDeckSize;           //cards remaining in the current game

  // // Original array of coordinates to demonstrate the use of the shuffle function
  // Coordinate ogPointsArray[ARR_SIZE];
  // // For demonstration purposes, this will be used to store a copy of the original array of coordinates before shuffling
  // Coordinate cpPointsArray[ARR_SIZE];
  // int currentArrSize = 0;

  // // Populate the original array
  // for (currentArrSize = 0; currentArrSize < 5; currentArrSize++)
  // {
  //   ogPointsArray[currentArrSize].x = currentArrSize + 1;
  //   ogPointsArray[currentArrSize].y = currentArrSize + 1;
  // }

  // // Sample call of a function from helpers_2.c to initialize random number generator
  // initRandom();

  // // Sample call of a function from helpers_2.c to get a random seed
  // int seed = randomInt();

  // // Sample call of a function from helpers_1.c to display initial array
  // printf("Initial array:\n  ");
  // displayCoodinates(ogPointsArray, currentArrSize);

  // printf("----- Different seeds produce different shuffle arrangements -----\n\n");

  // // Copy original array to preserve it for future shuffling
  // copyCoordinates(cpPointsArray, ogPointsArray, currentArrSize);
  // // Sample call of a function from helpers_2.c to shuffle the array
  // shuffle(cpPointsArray, currentArrSize, sizeof(Coordinate), seed);

  // // Sample call of a function from helpers_1.c to display shuffled array
  // printf("Shuffled array (seed: %d)\n  ", seed);
  // displayCoodinates(cpPointsArray, currentArrSize);

  // // Copy original array to preserve it for future shuffling
  // copyCoordinates(cpPointsArray, ogPointsArray, currentArrSize);

  // // Shuffle again with a different random seed
  // seed = randomInt();
  // shuffle(cpPointsArray, currentArrSize, sizeof(Coordinate), seed);
  // printf("Shuffled array (seed: %d)\n  ", seed);
  // displayCoodinates(cpPointsArray, currentArrSize);

  // // Providing the same seed produces the same shuffle arrangement
  // printf("----- Same seed produces the same shuffle arrangement -----\n\n");

  // // Copy original array to preserve it for future shuffling
  // copyCoordinates(cpPointsArray, ogPointsArray, currentArrSize);

  // // Shuffle with seed 999
  // shuffle(cpPointsArray, currentArrSize, sizeof(Coordinate), 999);
  // printf("Shuffled array (seed: 999):\n  ");
  // displayCoodinates(cpPointsArray, currentArrSize);

  // // Copy original array to preserve it for future shuffling
  // copyCoordinates(cpPointsArray, ogPointsArray, currentArrSize);

  // // Shuffle with seed 999 again
  // shuffle(cpPointsArray, currentArrSize, sizeof(Coordinate), 999);
  // printf("Shuffled array (seed: 999):\n  ");
  // displayCoodinates(cpPointsArray, currentArrSize);

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
