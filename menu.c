/******************************************************************************
 *  Description     : Organizer for game mechanics.
 *  Author/s        : Dy, Jasmine Yzabelle
 *                    Reyes, Kaitlyn Raine
 *  Section         : S22A, S13A
 *  Last Modified   : 3 / 14 / 2026
 ******************************************************************************/
 #include "defs.h"

void lineBreak() {
    int i;
    for(i=0; i<BOARDER_SIZE_HORIZONTAL; i++)
        printf("=");
}

/*
    This function displays visuals for four choices.

    @param      *n1     Define string for 1st choice.
    @param      *n2     Define string for 2nd choice.
    @param      *n3     Define string for 3rd choice.
    @param      *n4     Define string for 4th choice.

*/
void display4Choices(const char *n1, const char *n2, const char *n3, const char *n4) {
    printf("[1] %s\n", n1);
    printf("[2] %s\n", n2);
    printf("[3] %s\n", n3);
    printf("[4] %s\n", n4);
}

/**
 * This function will ask for the number of players
 * 
 * @return  The number of players
 */

int getNumPlayers(){
    int numPlayers;

    do{
        printf("How many players? ");
        scanf("%d", &numPlayers);
        while (getchar() != '\n');

        if(numPlayers < 3 || numPlayers > 6)
            printf("Input again. A minimum of 3 players and a mximum of 6 players.\n");
    }while(numPlayers < 3 || numPlayers > 6);

    return numPlayers;
 }

 /**
  * Asks the new player for their username and add them as a new player
  * 
  * @param player The array where the new player will be store
  * @param playerCount The current number of registered players
  */
 void registerPlayer(Player player[], int* playerCount){
    User newUsername;
    int exists = 0;
    int i;

    do{
        exists = 0; //reset to 0 so user can try to input again

        printf("New player username: ");
        scanf("%s", newUsername);
        while (getchar() != '\n');

        for(i = 0; i < *playerCount; i++){
            if(strcmp(player[i].name, newUsername) == 0){
                printf("Username already exists.\n");
                exists = 1;
            }    
        }
    }while(exists == 1);

    *playerCount += 1;
    strcpy(player[*playerCount-1].name, newUsername);
    player[*playerCount-1].wins = 0;
    player[*playerCount-1].highestScore = 0;
 }

 /**
  * This functions allows the user to select the players of the game.
  * 
  * @param player The array of players
  * @param numRegPlayer The number of players that already exist
  * @param playing The array of of players that will be playing
  */
 void playerSelection(Player players[], int* numRegPlayer, Player playing[]){
    int i, j, numPlayers;
    int choice;

    numPlayers = getNumPlayers();

    //ask which player will play
    for(i = 0; i < numPlayers; i++){
        printf("Select Player %d\n", i+1);
        printf("[0] <Add new player>\n");

        for(j = 0; j < *numRegPlayer; j++)
            printf("[%d] %s\n", j + 1, players[j].name);

        do{
            printf(">> ");
            scanf("%d", &choice);
            while (getchar() != '\n');

            if(choice < 0 || choice > *numRegPlayer)
                printf("Invalid input.\n");

        }while(choice < 0 || choice > *numRegPlayer);

        if(choice == 0){
            registerPlayer(players, numRegPlayer);
            playing[i] = players[*numRegPlayer - 1];
        }
        else
            playing[i] = players[choice - 1];
    }
}