//--------------------------------------------------
// Game User Interface
//--------------------------------------------------
#define BOARDER_SIZE_HORIZONTAL 20

//--------------------------------------------------
// Typedefs
//--------------------------------------------------
typedef char User[37];

typedef struct{
    User name;
    int wins;
    int highestScore;
} Player;

//--------------------------------------------------
// Main Menu Text
//--------------------------------------------------
#define NEW_GAME "New Game"
#define TOP_PLAYERS "Top Players"
#define SETTINGS "Settings"
#define EXIT "Exit"
