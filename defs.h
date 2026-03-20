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

//+==================+
//|   my constants   |
//+==================+
#define MAX_PLAYERS 50              // program can handle max 50
#define MIN_GAME_PLAYERS 3          // minimum players needed to play a game
#define MAX_GAME_PLAYERS 6          // maximum players for a game
#define TOTAL_CARDS 84              // Each color card (based on the front) has 12 cards, making a total of 84 cards in a standard Mantis game deck.
#define CARD_FILE "mantis.txt"      //Filename of the mantis cards file
#define PLAYER_FILE "players.txt"   //Filename of the players file

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

//+==================+
//|    my typedefs   |
//+==================+

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
  int picked; //flag to see if the player has been picked in player selection
}Player;

/**
 * Represents a card from mantis.txt
 */
typedef struct{
  char front;   // The actual color of the card
  char back[4]; // The colors it could possibly be
  int point;    // The points of the card
}Card;

/**
 * Represents the players state during a game
 */
typedef struct{
  Player *player;
  int tank[7]; //counts of cards per color. 0 = red, 1 = orange, and so on
  int tankPoints[7]; // stores the points of each color 0 = red, 1 = orange, and so on
  int score;
}GamePlayer;

/**
 * Represents the settings of the game
 */
typedef struct{
  int winningPoints;
  int seed;
}Settings;

//+==========================+
//|    function prototypes   |
//+==========================+
// game.c
void getNumPlaying(int *numGamePlayers);
int usernameExists(Player players[], int numPlayers, User name);
void registerPlayer(Player players[], int *numPlayers, int *success);
void playerSelection(Player players[], int *numPlayers, GamePlayer gamePlayers[], int numGamePlayers);
int hasColor(Card card, GamePlayer player);
int getColorIndex(char color);
void tryToScore(Card gameDeck[], int *gameDeckSize, GamePlayer *player);
void tryToSteal(Card gameDeck[], int *gameDeckSize, GamePlayer gamePlayers[], int numGamePlayers, int currentPlayerIndex);
void displayGameState(GamePlayer gamePlayers[], int numGamePlayers, Card gameDeck[], int gameDeckSize);
void shuffleAndDeal(Card deck[], Card gameDeck[], int *gameDeckSize, GamePlayer gamePlayers[], int numGamePlayers, int seed);
Card drawCard(Card gameDeck[], int *gameDeckSize);
void addToTank(GamePlayer *gamePlayer, Card card);
int checkWinner(GamePlayer gamePlayers[], int numGamePlayers, int gameDeckSize, int winningPoints);
void showResults(GamePlayer gamePlayers[], int numGamePlayers, int winnerIndex);
void gameStart(Player players[], int numPlayers, GamePlayer gamePlayers[], int numGamePlayers, Card deck[], Card gameDeck[], int *gameDeckSize, Settings currSettings);

// menu.c
void displayTitle();
void newGame(Player players[], int *numPlayers, GamePlayer gamePlayers[], int *numGamePlayers, Card deck[], Card gameDeck[], int *gameDeckSize, Settings currSettings);
void sortByWins(Player players[], Player topWins[], int numPlayers);
void sortByScore(Player players[], Player topScore[], int numPlayers);
void displayTop10ByWins(Player players[], Player topWins[], int numPlayers);
void displayTop10ByScore(Player players[], Player topScore[], int numPlayers);
void displayTop10(Player players[], Player topWins[], Player topScore[], int numPlayers);
void changeSettings(Settings *currSettings);
void mainMenu(Player players[], Player topWins[], Player topScore[], int *numPlayers, GamePlayer gamePlayers[], Settings *currSettings, int *numGamePlayers, Card deck[], Card gameDeck[], int *gameDeckSize);

// mp_template.c
void mantisToStruct(Card deck[]);
void playersToStruct(Player players[], int *numPlayers);
void savePlayers(Player players[], int numPlayers);

#endif // DEFS_H Include this to prevent redefinition error