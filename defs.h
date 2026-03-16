/******************************************************************************
 *  Description     : <short description of the file>
 *  Author/s        : <student1 full name (last name, first name)>
 *                    <student2 full name (last name, first name)>
 *  Section         : <your section>
 *  Last Modified   : <date when last revision was made>
 ******************************************************************************/

#ifndef DEFS_H // Include this to prevent redefinition error
#define DEFS_H // Include this to prevent redefinition error

/******************************************************************************
 * NOTE: These definitions are placed here in defs.h to demonstrate code
 * modularization across multiple files. You may move them to different files
 * if it better fits your code organization.
 ******************************************************************************/

#define PI 3.1415
#define ARR_SIZE 10

//====================
//|   my constants   |
//====================
#define MAX_PLAYERS 50              // program can handle max 50
#define MIN_GAME_PLAYERS 3          // minimum players needed to play a game
#define MAX_GAME_PLAYERS 6          // maximum players for a game

/**
 * Represents a 2D point
 */
typedef struct
{
  int x; // The x-coordinate of a point
  int y; // The y-coordinate of a point
} Coordinate;

/**
 * Represents a date
 */
typedef struct
{
  int day;   // The day [1-31]
  int month; // The integer representation of the month [1-12]
  int year;  // The year
} Date;

//====================
//|    my typedefs   |
//====================

/**
 * Typdef to create string for username
 */
typedef char User[37];

/**
 * Represents player information
 */
typedef struct{
  User name;
  int wins;
  int highestScore;
}Player;

typedef struct{
  char front;   // The actual color of the card
  char back[4]; // The colors it could possible be
  int point;    // The points of the card
}Card;

#endif // DEFS_H; Include this to prevent redefinition error