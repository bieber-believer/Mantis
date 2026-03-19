/******************************************************************************
 *  Description     : Organizer to locate user-defined functions such as Macros, Typedefs, and Structures.
 *  Author/s        : Dy, Jasmine Yzabelle
 *                    Reyes, Kaitlyn Raine
 *  Section         : S22A, S13A
 *  Last Modified   : 3 / 19 / 2026
 ******************************************************************************/

#ifndef DEFS_H // Include this to prevent redefinition error
#define DEFS_H // Include this to prevent redefinition error

//--------------------------------------------------
// Game User Interface
//--------------------------------------------------
#define BOARDER_SIZE_HORIZONTAL 20


//--------------------------------------------------
// Files
//--------------------------------------------------
#define PLAYER_DATA "data\\players.txt"
#define PLAYER_STATS "data\\stats.txt"
#define LEADERBOARD "data\\leaderboard.txt"

//--------------------------------------------------
// Numerical Macros
//--------------------------------------------------
#define PI 3.1415
#define ARR_SIZE 10
#define MAX_USER 37
#define MAX_PLAYERS 50


//--------------------------------------------------
// User-defined Typedefs
//--------------------------------------------------
typedef char User[MAX_USER];


//--------------------------------------------------
// Player Information
//--------------------------------------------------

typedef struct{
  User name;
  int wins;
  int highestScore;
} Player;


//--------------------------------------------------
// Pre-defined Typedefs
//--------------------------------------------------

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

//--------------------------------------------------
// Text Macros
//--------------------------------------------------

// Main Menu
#define NEW_GAME "New Game"
#define TOP_PLAYERS "Top Players"
#define SETTINGS "Settings"
#define EXIT "Exit"

//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------
int getNumPlayers();

#endif // DEFS_H; Include this to prevent redefinition error