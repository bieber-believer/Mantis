/******************************************************************************
 *  Description     : Header file. Has typedefs and function prototypes
 *  Author/s        : Dy, Jasmine Yzabelle
 *  Section         : S22A
 *  Last Modified   : March 22, 2026
 ******************************************************************************/

#ifndef DEFSDY_H // Include this to prevent redefinition error
#define DEFSDY_H // Include this to prevent redefinition error

/* -----        constants        ----- */
#define CARD_FILE "mantis.txt"      // Mantis cards file
#define PLAYER_FILE "players.txt"   // Players file
#define MAX_PLAYERS 50              // Max number of players the program can handle
#define MIN_GAME_PLAYERS 3          // Minimum number of players needed to play a game
#define MAX_GAME_PLAYERS 6          // Max number of players for a game
#define TOTAL_CARDS 84              // Each color card has 12 cards, making a total of 84 cards in a standard Mantis game deck
#define PLAYER_INFO 3               // Number of parts in a players information

/* -----     type definitions    ----- */

/**
 * String for a player's username
 */
typedef char User[37];

/**
 * Represents a player's information
 */
typedef struct{
    User name;
    int wins;
    int highestScore;
    int picked; // a flag just to help see if the players has been picked in player selection
}Player;

/**
 * Represents a card
 */
typedef struct{
    char front;     // the actual color of the card
    char back[4];   // the colors it could possible be
    int point;      // the points of the card
}Card;

/**
 * Represents a player's state during a game
 */
typedef struct{
    Player *player;
    int tank[7]; // the number of cards per color; 0 = red, 1 = yellow, ... , 6 = violet
    int tankPoints[7]; // the points of each color; 0 = red, 1 = yellow, ... , 6 = violet
    int score;
}GamePlayer;

/**
 * Represent of the settings of the game
 */
typedef struct{
    int winningPoints;
    int seed;
}Settings;

/* -----   function prototypes   ----- */
//files.c
void mantisToStruct(Card deck[]);
void playersToStruct(Player players[], int *numPlayers);
void savePlayers(Player players[], int numPlayers);

//design.c
void displayTitle();
void pressAnyKey();
void displayHeader();
void displayDrawnCard(Card card);
void displayTrophy();
void printRainbow(char *str);

//menu.c
void newGame(Player players[], int *numPlayers, GamePlayer gamePlayers[], int *numGamePlayers, Card deck[], int *deckSize, Settings currSettings);
void displayHowToPlay();
void sortByWins(Player players[], Player topWins[], int numPlayers);
void sortByScore(Player players[], Player topScore[], int numPlayers);
void displayTop10Wins(Player topWins[], int numPlayers);
void displayTop10Score(Player topScore[], int numPlayers);
void displayTop10(Player players[], Player topWins[], Player topScore[], int numPlayers);
void changeSettings(Settings *currSettings);
void displayAcknowledgements();
void mainMenu(Player players[], Player topWins[], Player topScore[], int *numPlayers, Settings *currSettings, GamePlayer gamePlayers[], int *numGamePlayers, Card deck[], int *deckSize);

//game.c
void getNumPlaying(int *numGamePlayers);
int usernameExists(Player players[], int numPlayers, User name);
void registerPlayer(Player players[], int *numPlayers, int *success);
void playerSelection(Player players[], int *numPlayers, GamePlayer gamePlayers[], int numGamePlayers);
int hasColor(Card card, GamePlayer player);
int getColorIndex(char color);
Card drawCard(Card deck[], int *deckSize);
void addToTank(GamePlayer *gamePlayer, Card card);
void shuffleAndDeal(Card deck[], int *deckSize, GamePlayer gamePlayers[], int numGamePlayers, int seed);
void tryToScore(Card deck[], int *deckSize, GamePlayer *player);
void tryToSteal(Card deck[], int *deckSize, GamePlayer gamePlayers[], int numGamePlayers, int currentPlayerIndex);
void displayGameState(GamePlayer gamePlayers[], int numGamePlayers, Card deck[], int deckSize);
int checkWinner(GamePlayer gamePlayers[], int numGamePlayers, int deckSize, int winnningPoints);
void showResults(GamePlayer gamePlayers[], int numGamePlayers, int winnderIndex);
void gameStart(Player players[], int numPlayers, GamePlayer gamePlayers[], int numGamePlayers, Card deck[], int *deckSize, Settings currSettings);

#endif